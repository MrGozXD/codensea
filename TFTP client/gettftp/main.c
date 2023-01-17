#include "header.h"

#define MODE "octet"

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
    hints.ai_family=AF_UNSPEC;
    hints.ai_protocol=IPPROTO_UDP;
    hints.ai_socktype=SOCK_DGRAM;
    
    
    
   
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

    //int resultConnect=connect(socketFD, res->ai_addr, res->ai_addrlen);
    //didSucceed(resultConnect, "connect");

   // Read Request Packet FTP 
    /*
    int count = 0;
    char buffer[BUFFER_SIZE];
    buffer[count++]=0;
    buffer[count++]=1;
    strcpy(&buffer[count], file);
    count+=strlen(file);
    buffer[count]=0;

    strcpy(&buffer[count+1],MODE);
    count+=strlen(MODE)+1;
    buffer[count]=0;

    for (int i = 0; i < count+1; i++)
    {
        printf("buffer[%d]: %d\n", i, buffer[i]);
    }
    */
    
    char *buffer=setBuffer(file, MODE, RRQ);
    printf("buffer: %s\n", buffer);
    int sizeBuffer=strlen(file)+strlen(MODE)+4;
    //int resultSendTo=sendto(socketFD, buffer, count+1,res->ai_flags, res->ai_addr, res->ai_addrlen);
    int resultSendTo=sendto(socketFD, buffer, sizeBuffer,res->ai_flags, res->ai_addr, res->ai_addrlen);

    if(resultSendTo <0)
    {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
    printf("Coucou\n");
    printf("resultSendTo: %d\n", resultSendTo);
    didSucceed(resultSendTo, "sendto");

    //int resultRecvFrom=recvfrom(socketFD, buffer, BUFFER_SIZE, 0, res->ai_addr, &res->ai_addrlen);
/*
    int resultRecv=recvfrom(socketFD, buffer, BUFFER_SIZE, 0);
    didSucceed(resultRecv, "recvfrom");

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



