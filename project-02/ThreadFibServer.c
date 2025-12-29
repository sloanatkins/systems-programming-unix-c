#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------
#define PIPE_NAME "FIBOPIPE"
#define INTERFACE_PROGRAM "./FibInterface.out"

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
static int g_running_threads = 0;
static pthread_mutex_t g_thread_count_mutex = PTHREAD_MUTEX_INITIALIZER;
static pid_t g_interface_pid = -1;
static volatile sig_atomic_t g_sigxcpu_received = 0;

//-----------------------------------------------------------------------------
// Structures
//-----------------------------------------------------------------------------
typedef struct {
    long fib_number;
} ThreadData;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
// Compute Nth Fibonacci number recursively
long Fibonacci(long WhichNumber) {
    if (WhichNumber <= 1) {
        return(WhichNumber);
    } else {
        return(Fibonacci(WhichNumber - 2) + Fibonacci(WhichNumber - 1));
    }
}

// Get current CPU time in seconds and microseconds
void GetCPUTime(long* seconds, long* microseconds) {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    *seconds = usage.ru_utime.tv_sec;
    *microseconds = usage.ru_utime.tv_usec;
}

// Print current CPU usage
void ReportCPUTime(void) {
    long seconds, microseconds;
    GetCPUTime(&seconds, &microseconds);
    printf("S: Server has used %lds %ldus\n", seconds, microseconds);
    fflush(stdout);
}

// Thread function to compute Fibonacci number
void* FibonacciThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    long result = Fibonacci(data->fib_number);
    
    printf("S: Fibonacci %ld is %ld\n", data->fib_number, result);
    fflush(stdout);
    
    pthread_mutex_lock(&g_thread_count_mutex);
    g_running_threads--;
    pthread_mutex_unlock(&g_thread_count_mutex);
    
    free(data);
    return NULL;
}

// Signal handler for SIGXCPU
void SigxcpuHandler(int sig) {
    (void)sig;
    
    if (g_sigxcpu_received) {
        return;
    }
    
    g_sigxcpu_received = 1;
    
    signal(SIGXCPU, SIG_IGN);
    
    printf("S: Received a SIGXCPU, ignoring any more\n");
    fflush(stdout);
    
    if (g_interface_pid > 0) {
        printf("S: Received a SIGXCPU, sending SIGUSR1 to interface\n");
        fflush(stdout);
        kill(g_interface_pid, SIGUSR1);
    }
}

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    int pipe_fd;
    long cpu_limit;
    struct rlimit limit;
    struct sigaction sa;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <cpu_limit_seconds>\n", argv[0]);
        exit(1);
    }
    
    cpu_limit = atol(argv[1]);
    printf("S: Setting CPU limit to %lds\n", cpu_limit);
    fflush(stdout);
    
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = SigxcpuHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGXCPU, &sa, NULL);
    
    limit.rlim_cur = cpu_limit;
    limit.rlim_max = cpu_limit;
    setrlimit(RLIMIT_CPU, &limit);
    
    unlink(PIPE_NAME);
    
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    
    g_interface_pid = fork();
    if (g_interface_pid == -1) {
        perror("fork");
        unlink(PIPE_NAME);
        exit(1);
    }
    
    if (g_interface_pid == 0) {
        execl(INTERFACE_PROGRAM, INTERFACE_PROGRAM, PIPE_NAME, NULL);
        perror("execl");
        exit(1);
    }
    
    pipe_fd = open(PIPE_NAME, O_RDONLY);
    if (pipe_fd == -1) {
        perror("open pipe");
        unlink(PIPE_NAME);
        exit(1);
    }
    
    while (1) {
        long number;
        ssize_t bytes_read;
        
        bytes_read = read(pipe_fd, &number, sizeof(long));
        
        if (bytes_read == -1) {
            if (errno == EINTR && g_sigxcpu_received) {
                break;
            }
            perror("read");
            break;
        }
        
        if (bytes_read == 0) {
            break;
        }
        
        if (number == 0) {
            break;
        }
        
        ReportCPUTime();
        
        printf("S: Received %ld from interface\n", number);
        fflush(stdout);
        
        ThreadData* data = (ThreadData*)malloc(sizeof(ThreadData));
        data->fib_number = number;
        
        pthread_t thread;
        pthread_mutex_lock(&g_thread_count_mutex);
        g_running_threads++;
        pthread_mutex_unlock(&g_thread_count_mutex);
        
        if (pthread_create(&thread, NULL, FibonacciThread, data) != 0) {
            perror("pthread_create");
            free(data);
            pthread_mutex_lock(&g_thread_count_mutex);
            g_running_threads--;
            pthread_mutex_unlock(&g_thread_count_mutex);
            continue;
        }
        
        pthread_detach(thread);
        printf("S: Created and detached the thread for %ld\n", number);
        fflush(stdout);
    }
    
    close(pipe_fd);
    
    while (1) {
        pthread_mutex_lock(&g_thread_count_mutex);
        int count = g_running_threads;
        pthread_mutex_unlock(&g_thread_count_mutex);
        
        if (count == 0) {
            break;
        }
        
        printf("S: Waiting for %d threads\n", count);
        fflush(stdout);
        sleep(1);
    }
    
    ReportCPUTime();
    
    int status;
    pid_t result = waitpid(g_interface_pid, &status, 0);
    if (result > 0) {
        printf("S: Child %d completed with status %d\n", result, WEXITSTATUS(status));
        fflush(stdout);
    }
    
    unlink(PIPE_NAME);
    
    return 0;
}
//-----------------------------------------------------------------------------
