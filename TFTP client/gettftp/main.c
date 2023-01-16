#include "header.h"


int main(int argc, char const *argv[])
{
    char const *host=argv[1];
    char const *file=argv[2];
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_protocol=IPPROTO_TCP;
    hints.ai_socktype=SOCK_STREAM;
    
   
    struct addrinfo *res;

    int resultAddrInfo=getaddrinfo(argv[1], NULL, &hints, &res);
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
}



