//------------------------------------------------------------------------------
// SignalSender.c
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
#define ALARM_INTERVAL 5
#define MAX_ALARMS 3

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
void HandleSIGINT(int signum);
void HandleSIGALRM(int signum);
void StartReceiver(void);
void RunMainLoop(pid_t childPid);
void CleanupChild(pid_t childPid);

//------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------
int alarmCount = 0;
pid_t receiverPid = 0;

//------------------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------------------
int main(void) {

    receiverPid = fork();

    if (receiverPid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (receiverPid == 0) {
        execl("./SignalReceiver", "./SignalReceiver", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, HandleSIGINT);
    signal(SIGALRM, HandleSIGALRM);

    alarm(ALARM_INTERVAL);

    RunMainLoop(receiverPid);
    CleanupChild(receiverPid);

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// Function HandleSIGINT
//------------------------------------------------------------------------------
void HandleSIGINT(int signum) {
    printf("SignalSender just got an interrupt\n");
    fflush(stdout);

    alarm(ALARM_INTERVAL);

    kill(receiverPid, SIGUSR1);
}

//------------------------------------------------------------------------------
// Function HandleSIGALRM
//------------------------------------------------------------------------------
void HandleSIGALRM(int signum) {
    alarmCount++;

    printf("SignalSender just got alarm %d\n", alarmCount);
    fflush(stdout);

    if (alarmCount < MAX_ALARMS) {
        alarm(ALARM_INTERVAL);
    }
}

//------------------------------------------------------------------------------
// Function RunMainLoop
//------------------------------------------------------------------------------
void RunMainLoop(pid_t childPid) {
    while (alarmCount < MAX_ALARMS) {
        pause();
    }
}

//------------------------------------------------------------------------------
// Function CleanupChild
//------------------------------------------------------------------------------
void CleanupChild(pid_t childPid) {
    alarm(0);
    kill(childPid, SIGKILL);
    waitpid(childPid, NULL, 0);
}

//------------------------------------------------------------------------------

