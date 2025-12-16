//------------------------------------------------------------------------------
// SocketClient.c
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mysockets.h"

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
#define SEND_BUFFER_SIZE 1024

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
void ConnectAndSend(char* hostName, int portNumber);

//------------------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    char* hostName;
    int portNumber;
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    hostName = argv[1];
    portNumber = atoi(argv[2]);
    
    ConnectAndSend(hostName, portNumber);
    
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// Function ConnectAndSend
//------------------------------------------------------------------------------
void ConnectAndSend(char* hostName, int portNumber) {
    int callingSocket;
    char buffer[SEND_BUFFER_SIZE];
    char myHostName[MAX_HOST_NAME + 1];
    char myDomainName[MAX_HOST_NAME + 1];
    ssize_t bytesSent;
    
    callingSocket = CallSocket(hostName, portNumber);
    
    if (callingSocket < 0) {
        fprintf(stderr, "ERROR: Could not connect to server\n");
        exit(EXIT_FAILURE);
    }
    
    gethostname(myHostName, MAX_HOST_NAME);
    getdomainname(myDomainName, MAX_HOST_NAME);
    
    snprintf(buffer, SEND_BUFFER_SIZE, "%s.%s\n", myHostName, myDomainName);
    
    bytesSent = send(callingSocket, buffer, strlen(buffer), 0);
    
    if (bytesSent < 0) {
        perror("send failed");
        CloseSocket(callingSocket);
        exit(EXIT_FAILURE);
    }
    
    CloseSocket(callingSocket);
}

//------------------------------------------------------------------------------
