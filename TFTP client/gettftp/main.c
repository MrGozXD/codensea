#include "header.h"

#define MODE "octet"

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        char *port = "1069";
    }
    char const *host = argv[1]; // my IP :192.168.33.72
    char const *file = argv[2];
    char const *port = argv[3];
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_socktype = SOCK_DGRAM;

    struct addrinfo *res;

    int resultAddrInfo = getaddrinfo(host, port, &hints, &res); // Doesn't need a domain name, just an IP address. If given a domain name,it will make DNS request by itselft.

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

    int resultNameInfo = getnameinfo(res->ai_addr, res->ai_addrlen, hostName, sizeof(hostName), servName, sizeof(servName), NI_NUMERICHOST | NI_NUMERICSERV);

    if (resultNameInfo != 0)
    {
        dispGetNameInfoFailed(resultNameInfo);
    }
    else
    {
        dispGetNameInfoSucceeded(hostName, servName);
    }

    int socketFD = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    didSucceed(socketFD, "socket");

    // int resultConnect=connect(socketFD, res->ai_addr, res->ai_addrlen);
    // didSucceed(resultConnect, "connect");

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

    char *buffer = setBuffer(file, MODE, RRQ);
    int sizeBuffer = strlen(file) + strlen(MODE) + 4;
    // int resultSendTo=sendto(socketFD, buffer, count+1,res->ai_flags, res->ai_addr, res->ai_addrlen);
    int resultSendTo = sendto(socketFD, buffer, sizeBuffer, res->ai_flags, res->ai_addr, res->ai_addrlen);
    //printf("Coucou\n");
    //printf("resultSendTo: %d\n", resultSendTo);
    didSucceed(resultSendTo, "sendto");

    int resultRecvFrom = recvfrom(socketFD, buffer, BUFFER_SIZE, res->ai_flags, res->ai_addr, &res->ai_addrlen);
    printf("resultRecvFrom: %d\n", resultRecvFrom);
    didSucceed(resultRecvFrom, "recvfrom");
    if (buffer[1]!=3)
    {
        printf("Received unexpected packet type: %d\n", buffer[1]);
    }

    for (int i = 0; i < resultRecvFrom+5; i++)
    {
        printf("buffer[%d]: %d\n", i, buffer[i]);
    }


    int blockNumber = 1;
    while(resultRecvFrom=BUFFER_SIZE+4)
    {
        char *ACK = setACKBuffer(blockNumber);
        int resultSendToACK = sendto(socketFD, ACK, 4, res->ai_flags, res->ai_addr, res->ai_addrlen);
        didSucceed(resultSendToACK, "sendto");
        blockNumber++;
        resultRecvFrom = recvfrom(socketFD, buffer, BUFFER_SIZE, res->ai_flags, res->ai_addr, &res->ai_addrlen);
        printf("resultRecvFrom: %d\n", resultRecvFrom);
        didSucceed(resultRecvFrom, "recvfrom");
        if (buffer[1]!=3)
        {
            printf("Received unexpected packet type: %d\n", buffer[1]);
        }
    }

    // TODO : function to retrieve the data from the buffer
    // TODO : function to write the data in a file
    /*
    char *ACK = setACKBuffer(blockNumber);
    int resultSendToACK = sendto(socketFD, ACK, 4, res->ai_flags, res->ai_addr, res->ai_addrlen);
    didSucceed(resultSendToACK, "sendto");
    
    char *buffer2 = malloc(sizeof(char) * BUFFER_SIZE);
    int resultRecvFrom2 = recvfrom(socketFD, buffer2, BUFFER_SIZE, res->ai_flags, res->ai_addr, &res->ai_addrlen);
    printf("resultRecvFrom2: %d\n", resultRecvFrom2);
    didSucceed(resultRecvFrom2, "recvfrom");
    if (buffer2[1]!=3)
    {
        printf("Received unexpected packet type: %d\n", buffer2[1]);
    }
    for (int i = 0; i < BUFFER_SIZE+1; i++)
    {
        printf("buffer2[%d]: %d\n", i, buffer2[i]);
    }
    // send ACK to server
    int blockNumber2 = 2;
    char *ACK2 = setACKBuffer(blockNumber2);
    int resultSendToACK2 = sendto(socketFD, ACK2, 4, res->ai_flags, res->ai_addr, res->ai_addrlen);
    didSucceed(resultSendToACK2, "sendto");
*/


    /*
    int blockNumber = buffer[2] * 256 + buffer[3];
    printf("blockNumber: %d\n", blockNumber);
    int count = 0;
    char *fileContent = malloc(sizeof(char) * MAX_BLOCK_SIZE);
    while (resultRecvFrom > 4)
    {
        for (int i = 4; i < resultRecvFrom; i++)
        {
            fileContent[count++] = buffer[i];
        }
        blockNumber++;
        buffer[2] = blockNumber / 256;
        buffer[3] = blockNumber % 256;
        resultSendTo = sendto(socketFD, buffer, 4, res->ai_flags, res->ai_addr, res->ai_addrlen);
        didSucceed(resultSendTo, "sendto");
        resultRecvFrom = recvfrom(socketFD, buffer, BUFFER_SIZE, res->ai_flags, res->ai_addr, &res->ai_addrlen);
        didSucceed(resultRecvFrom, "recvfrom");
        if (buffer[1]!=3)
        {
            printf("Received unexpected packet type: %d\n", buffer[1]);
        }
        if (buffer[2] != blockNumber / 256 || buffer[3] != blockNumber % 256)
        {
            printf("Received unexpected block number: %d\n", buffer[2] * 256 + buffer[3]);
        }
    }
    printf("fileContent: %s\n", fileContent);
    freeaddrinfo(res);
    free(buffer);
    free(fileContent);
    */
    
}
