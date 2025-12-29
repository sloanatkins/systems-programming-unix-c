//------------------------------------------------------------------------------
// SocketServer.c
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mysockets.h"

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
#define RECV_BUFFER_SIZE 1024

//------------------------------------------------------------------------------
// Function Prototypes
//------------------------------------------------------------------------------
void RunServer(int portNumber);

//------------------------------------------------------------------------------
// Main Program
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    int portNumber;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    portNumber = atoi(argv[1]);
    
    RunServer(portNumber);
    
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
// Function RunServer
//------------------------------------------------------------------------------
void RunServer(int portNumber) {
    int listeningSocket;
    int connectionSocket;
    char buffer[RECV_BUFFER_SIZE];
    ssize_t bytesReceived;
    
    listeningSocket = Establish(portNumber);
    
    if (listeningSocket < 0) {
        fprintf(stderr, "ERROR: Could not establish listening socket\n");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        connectionSocket = GetConnection(listeningSocket);
        
        if (connectionSocket < 0) {
            continue;
        }
        
        printf("SERVER: Received a connection\n");
        fflush(stdout);
        
        memset(buffer, 0, RECV_BUFFER_SIZE);
        bytesReceived = recv(connectionSocket, buffer, RECV_BUFFER_SIZE - 1, 0);
        
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            printf("SERVER: That was %s", buffer);
            fflush(stdout);
        }
        
        CloseSocket(connectionSocket);
    }
    
    CloseSocket(listeningSocket);
}

//------------------------------------------------------------------------------
