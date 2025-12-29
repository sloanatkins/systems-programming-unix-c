//------------------------------------------------------------------------------
// L12_ThreadBuffer.c
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
#define BUFFER_SIZE 1024

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
void* ProducerThread(void* arg);
void* ConsumerThread(void* arg);

//------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------
char globalBuffer[BUFFER_SIZE];

//------------------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------------------
int main(void) {
    pthread_t producer;
    pthread_t consumer;
    
    globalBuffer[0] = '\0';
    
    pthread_create(&producer, NULL, ProducerThread, NULL);
    pthread_create(&consumer, NULL, ConsumerThread, NULL);
    
    pthread_detach(producer);
    pthread_detach(consumer);
    
    printf("Exiting the main program, leaving the threads running\n");
    fflush(stdout);
    
    sleep(86400);
    
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// Function ProducerThread
//------------------------------------------------------------------------------
void* ProducerThread(void* arg) {
    char input[BUFFER_SIZE];
    
    usleep(100000);
    
    while (1) {
        while (globalBuffer[0] != '\0') {
            sched_yield();
        }
        
        printf("Enter buffer data: ");
        fflush(stdout);
        
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            exit(EXIT_SUCCESS);
        }
        
        input[strcspn(input, "\n")] = '\0';
        
        strcpy(globalBuffer, input);
    }
    
    return NULL;
}

//------------------------------------------------------------------------------
// Function ConsumerThread
//------------------------------------------------------------------------------
void* ConsumerThread(void* arg) {
    while (1) {
        while (globalBuffer[0] == '\0') {
            sched_yield();
        }
        
        printf("The buffer contains %s\n", globalBuffer);
        fflush(stdout);
        
        globalBuffer[0] = '\0';
    }
    
    return NULL;
}

//------------------------------------------------------------------------------
