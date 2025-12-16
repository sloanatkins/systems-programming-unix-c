//------------------------------------------------------------------------------
// BatchExec.c
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
#define MAX_LINE_LENGTH 1024
#define MAX_ARGUMENTS   64
#define INITIAL_PID_CAPACITY 10

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
int  ParseCommand(char *line, char *args[]);
void ExecuteCommandsFromFile(const char *filename);
pid_t *CreatePidArray(int *capacity);
void AddPid(pid_t **pids, int *count, int *capacity, pid_t newPid);
void WaitForAllProcesses(pid_t *pids, int count);

//------------------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <command_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ExecuteCommandsFromFile(argv[1]);

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// Function ParseCommand
//------------------------------------------------------------------------------
int ParseCommand(char *line, char *args[]) {
    int argc = 0;
    char *token;

    line[strcspn(line, "\n")] = '\0';

    while (isspace(*line)) {
        line++;
    }

    if (*line == '\0' || *line == '#') {
        return 0;
    }

    token = strtok(line, " \t");
    while (token != NULL && argc < MAX_ARGUMENTS - 1) {
        args[argc++] = token;
        token = strtok(NULL, " \t");
    }

    args[argc] = NULL;
    return argc;
}

//------------------------------------------------------------------------------
// Function CreatePidArray
//------------------------------------------------------------------------------
pid_t *CreatePidArray(int *capacity) {
    pid_t *pids = (pid_t *)malloc((*capacity) * sizeof(pid_t));
    if (pids == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return pids;
}

//------------------------------------------------------------------------------
// Function AddPid
//------------------------------------------------------------------------------
void AddPid(pid_t **pids, int *count, int *capacity, pid_t newPid) {

    if (*count >= *capacity) {
        *capacity *= 2;
        pid_t *temp = (pid_t *)realloc(*pids, (*capacity) * sizeof(pid_t));

        if (temp == NULL) {
            perror("Memory reallocation failed");
            free(*pids);
            exit(EXIT_FAILURE);
        }

        *pids = temp;
    }

    (*pids)[(*count)++] = newPid;
}

//------------------------------------------------------------------------------
// Function ExecuteCommandsFromFile
//------------------------------------------------------------------------------
void ExecuteCommandsFromFile(const char *filename) {

    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    pid_t *pids;
    int pidCount = 0;
    int pidCapacity = INITIAL_PID_CAPACITY;

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    pids = CreatePidArray(&pidCapacity);

    while (fgets(line, sizeof(line), file) != NULL) {

        char lineCopy[MAX_LINE_LENGTH];
        char *args[MAX_ARGUMENTS];
        
        strncpy(lineCopy, line, MAX_LINE_LENGTH - 1);
        lineCopy[MAX_LINE_LENGTH - 1] = '\0';

        int argCount = ParseCommand(lineCopy, args);

        if (argCount == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            continue;
        }

        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }

        AddPid(&pids, &pidCount, &pidCapacity, pid);
    }

    fclose(file);

    WaitForAllProcesses(pids, pidCount);

    free(pids);
}

//------------------------------------------------------------------------------
// Function WaitForAllProcesses
//------------------------------------------------------------------------------
void WaitForAllProcesses(pid_t *pids, int count) {
    int status;

    for (int i = 0; i < count; i++) {
        waitpid(pids[i], &status, 0);
    }
}

//------------------------------------------------------------------------------

