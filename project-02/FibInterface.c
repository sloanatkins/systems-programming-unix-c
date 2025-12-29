#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
static volatile sig_atomic_t g_stop_loop = 0;
static volatile sig_atomic_t g_reading_interrupted = 0;

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
// Signal handler for SIGUSR1
void Sigusr1Handler(int sig) {
    (void)sig;
    
    printf("I: Received a SIGUSR1, stopping loop\n");
    fflush(stdout);
    g_stop_loop = 1;
    g_reading_interrupted = 1;
}

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    int pipe_fd;
    struct sigaction sa;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pipe_name>\n", argv[0]);
        exit(1);
    }
    
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = Sigusr1Handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    
    pipe_fd = open(argv[1], O_WRONLY);
    if (pipe_fd == -1) {
        perror("open pipe");
        exit(1);
    }
    
    while (!g_stop_loop) {
        long number;
        char buffer[256];
        
        printf("I: Which Fibonacci number do you want : ");
        fflush(stdout);
        
        g_reading_interrupted = 0;
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            if (g_reading_interrupted) {
                printf("I: Reading from user abandoned\n");
                fflush(stdout);
                number = 0;
            } else {
                break;
            }
        } else {
            number = atol(buffer);
        }
        
        if (g_stop_loop) {
            number = 0;
        }
        
        if (write(pipe_fd, &number, sizeof(long)) == -1) {
            perror("write");
            break;
        }
        
        fsync(pipe_fd);
        
        if (number == 0) {
            break;
        }
    }
    
    printf("I: Interface is exiting\n");
    fflush(stdout);
    
    close(pipe_fd);
    
    return 0;
}
//-----------------------------------------------------------------------------
