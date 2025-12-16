//-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "mysockets.h"
//-------------------------------------------------------------------------------------------------
void PrintIPAddress(char * SocketType,unsigned int Address) {

    printf("%s : ",SocketType);
    printf("%d.",Address & 0xFF);
    Address >>= 8;
    printf("%d.",Address & 0xFF);
    Address >>= 8;
    printf("%d.",Address & 0xFF);
    Address >>= 8;
    printf("%d",Address);
    printf("\n");
}
//-------------------------------------------------------------------------------------------------
int CreateSocketAddress(char *Hostname,int PortNumber,struct sockaddr_in *SocketAddress) {

    int Socket;
    struct hostent *HostEntry;

//----Get host entry and ensure it's an internet machine
    if ((HostEntry = gethostbyname(Hostname)) == NULL) {
        perror("Cannot get host entry");
        return(-1);
    }
    if (HostEntry->h_addrtype != AF_INET) {
        printf("ERROR: That's not an internet machine\n");
        return(-1);
    }

//----This is our host address and port number
    memset(SocketAddress,0,sizeof(struct sockaddr_in));
    SocketAddress->sin_family = AF_INET;
    SocketAddress->sin_addr.s_addr = htonl(INADDR_ANY);
    SocketAddress->sin_port = htons(PortNumber);
    memcpy(&SocketAddress->sin_addr,HostEntry->h_addr,HostEntry->h_length);

    if ((Socket = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        perror("Cannot create socket");
        return(-1);
    }

    return(Socket);
}
//-------------------------------------------------------------------------------------------------
int Establish(int PortNumber) { 

    char   MyName[MAX_HOST_NAME+1];
    struct sockaddr_in SocketAddress;
    int    Socket;

    gethostname(MyName,MAX_HOST_NAME);           
    if ((Socket = CreateSocketAddress(MyName,PortNumber,&SocketAddress)) == -1) {
        return(-1);
    }
    PrintIPAddress("Listening socket",SocketAddress.sin_addr.s_addr);
    if (bind(Socket,(struct sockaddr*) &SocketAddress,sizeof(SocketAddress)) < 0) {
        perror("Cannot bind");
        CloseSocket(Socket);
        return(-1);
    }

    listen(Socket,MAX_SOCKET_QUEUE);

    return(Socket);
}
//-------------------------------------------------------------------------------------------------
int CallSocket(char *Hostname,int PortNumber) {

    struct sockaddr_in SocketAddress;
    int Socket;

    if ((Socket = CreateSocketAddress(Hostname,PortNumber,&SocketAddress)) == -1) {
        return(-1);
    }
    PrintIPAddress("Calling socket",SocketAddress.sin_addr.s_addr);
    if (connect(Socket,(struct sockaddr*) &SocketAddress,sizeof(SocketAddress)) < 0) {
        perror("Cannot connect");
        CloseSocket(Socket);
        return(-1);
    }

    return(Socket);
}
//-------------------------------------------------------------------------------------------------
//----Wait for a connection to occur on a socket
int GetConnection(int AcceptSocket) { 

    int ConnectionSocket;

    if ((ConnectionSocket = accept(AcceptSocket,NULL,NULL)) < 0) {
        perror("Cannot get connection:");
        return(-1);
    }

    return(ConnectionSocket);
}
//-------------------------------------------------------------------------------------------------
void CloseSocket(int Socket) {

    close(Socket);
}
//-------------------------------------------------------------------------------------------------
int WriteData(int Socket,char *Buffer,int BytesToWrite) { 

    int TotalBytesWritten; 
    int BytesWritten;

    TotalBytesWritten = 0;
    BytesWritten = 0;
    while (TotalBytesWritten < BytesToWrite) {
        if ((BytesWritten = write(Socket,Buffer,BytesToWrite-TotalBytesWritten)) > 0) {
            TotalBytesWritten += BytesWritten;  // increment byte counter
            Buffer += BytesWritten;     // move buffer ptr for next read
        } else if (BytesWritten < 0) {  // signal an error to the caller
            return(-1);
        }
    }

    return(TotalBytesWritten);
}
//-------------------------------------------------------------------------------------------------
int ReadData(int Socket,char *Buffer,int MaxBytesToRead) {

    int TotalBytesRead;
    int BytesRead;

    TotalBytesRead = 0;
    BytesRead= 0;
    do {
        if ((BytesRead = read(Socket,Buffer,MaxBytesToRead-TotalBytesRead)) > 0) {
            TotalBytesRead += BytesRead;
            Buffer += BytesRead;
//----Bail out if eoln
            if (Buffer[-1] == '\n') {
                MaxBytesToRead = TotalBytesRead;
            }
//----If eof or error, return that
        }
    } while (BytesRead > 0 && TotalBytesRead < MaxBytesToRead);

    return(TotalBytesRead);
}
//-------------------------------------------------------------------------------------------------
