#include "header.h"


int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        char *port="1069";
    }
    char const *host=argv[1];   //my IP :192.168.33.72
    char const *file=argv[2];
    char const *port=argv[3];
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_protocol=IPPROTO_TCP;
    hints.ai_socktype=SOCK_STREAM;
    
   
    struct addrinfo *res;

    int resultAddrInfo=getaddrinfo(host, port, &hints, &res); //Doesn't need a domain name, just an IP address. If given a domain name,it will make DNS request by itselft.

    if (resultAddrInfo != 0)
    {
        dispGetAddrInfoFailed(resultAddrInfo);
    }
    else
    {
        dispGetAddrInfoSucceeded(res);
    }

    char hostName[BUFFER_SIZE];
    char servName[BUFFER_SIZE];

    int resultNameInfo=getnameinfo(res->ai_addr, res->ai_addrlen, hostName, sizeof(hostName), servName, sizeof(servName), NI_NUMERICHOST|NI_NUMERICSERV);

    if (resultNameInfo != 0)
    {
        dispGetNameInfoFailed(resultNameInfo);
    }
    else
    {
        dispGetNameInfoSucceeded(hostName, servName);
    }


    int socketFD=socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    didSucceed(socketFD, "socket");

    int resultConnect=connect(socketFD, res->ai_addr, res->ai_addrlen);
    didSucceed(resultConnect, "connect");

    /*
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    buffer[0]=0;
    buffer[1]=1;
    strcpy(buffer+2, file);
    buffer[strlen(file)+2]=0;
    buffer[strlen(file)+3]='o';
    buffer[strlen(file)+4]='c';
    buffer[strlen(file)+5]='t';
    buffer[strlen(file)+6]='e';
    buffer[strlen(file)+7]='t';
    buffer[strlen(file)+8]=0;

    int resultSend=send(socketFD, buffer, strlen(file)+9, 0);
    didSucceed(resultSend, "send");

    int resultRecv=recv(socketFD, buffer, BUFFER_SIZE, 0);
    didSucceed(resultRecv, "recv");

    int blockNumber=1;

    int resultWrite=write(socketFD, buffer+4, resultRecv-4);
    didSucceed(resultWrite, "write");

    while (resultRecv == MAX_BLOCK_SIZE)
    {
        memset(buffer, 0, sizeof(buffer));
        buffer[0]=0;
        buffer[1]=4;
        buffer[2]=blockNumber/256;
        buffer[3]=blockNumber%256;

        int resultSend=send(socketFD, buffer, 4, 0);
        didSucceed(resultSend, "send");

        int resultRecv=recv(socketFD, buffer, BUFFER_SIZE, 0);
        didSucceed(resultRecv, "recv");
        
        int resultWrite=write(socketFD, buffer+4, resultRecv-4);
        didSucceed(resultWrite, "write");

        blockNumber++;
    }
    */
}



