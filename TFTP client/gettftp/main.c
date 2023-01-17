#include "header.h"

/*
From RFC 1350

 2 bytes     string    1 byte     string   1 byte
 ------------------------------------------------
| Opcode |  Filename  |   0  |    Mode    |   0  |
 ------------------------------------------------

            Figure 5-1: RRQ/WRQ packet

2 bytes     2 bytes      n bytes
 ----------------------------------
| Opcode |   Block #  |   Data     |
 ----------------------------------

        Figure 5-2: DATA packet

2 bytes     2 bytes
 ---------------------
| Opcode |   Block #  |
 ---------------------

        Figure 5-3: ACK packet

Type   Op #     Format without header

        2 bytes    string   1 byte     string   1 byte
        -----------------------------------------------
RRQ/  | 01/02 |  Filename  |   0  |    Mode    |   0  |
WRQ    -----------------------------------------------
        2 bytes    2 bytes       n bytes
        ---------------------------------
DATA  | 03    |   Block #  |    Data    |
        ---------------------------------
        2 bytes    2 bytes
        -------------------
ACK   | 04    |   Block #  |
        --------------------
        2 bytes  2 bytes        string    1 byte
        ----------------------------------------
ERROR | 05    |  ErrorCode |   ErrMsg   |   0  |
        ----------------------------------------

*/

int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        char *port = "1069";
    }
    char const *host = argv[1]; // localhost = 127.0.0.1
    char const *file = argv[2];
    char const *port = argv[3];
    
    // filter
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

    char *buffer = setBuffer(file, MODE, RRQ);
    int sizeBuffer = strlen(file) + strlen(MODE) + 4;   buffer => 
    
    int resultSendTo = sendto(socketFD, buffer, sizeBuffer, res->ai_flags, res->ai_addr, res->ai_addrlen);
    didSucceed(resultSendTo, "sendto");

    int resultRecvFrom = recvfrom(socketFD, buffer, BUFFER_SIZE, res->ai_flags, res->ai_addr, &res->ai_addrlen);
    printf("resultRecvFrom: %d\n", resultRecvFrom);
    didSucceed(resultRecvFrom, "recvfrom");
    receivedData(buffer[1]);
    // debug
    /*
    for (int i = 0; i < resultRecvFrom+5; i++)
    {
        printf("buffer[%d]: %d\n", i, buffer[i]);
    }
    */


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
        receivedData(buffer[1]);
    }

    // TODO : function to retrieve the data from the buffer
    // TODO : function to write the data in a file
    /*
    printf("fileContent: %s\n", fileContent);
    freeaddrinfo(res);
    free(buffer);
    free(fileContent);
    */
    
}
