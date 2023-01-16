#include "header.h"

void dispGetAddrInfoFailed(int result)
{
    const char *errorMessage=gai_strerror(result);
    printf("Error: getaddrinfo failed\n");
    printf("Error message: %s\n", errorMessage);
    exit(1);
}

void dispGetAddrInfoSucceeded(struct addrinfo *res)
{
    struct addrinfo *tmp;
    for (tmp = res; tmp!=NULL; tmp=tmp->ai_next)
    {
        printf("Success: getaddrinfo succeeded\n");
        printf("res->ai_family: %d\n", tmp->ai_family);
        printf("res->ai_socktype: %d\n", tmp->ai_socktype);
        printf("res->ai_protocol: %d\n", tmp->ai_protocol);
    }
}

void dispGetNameInfoSucceeded(char *hostName, char *servName)
{
    printf("Success: getnameinfo succeeded\n");
    printf("host :%s\n", hostName);
    printf("serv :%s\n", servName);
}

void dispGetNameInfoFailed(int result)
{
    const char *errorMessageNameInfo=gai_strerror(result);
    printf("Error: getnameinfo failed\n");
    printf("Error message: %s\n", errorMessageNameInfo);
    exit(1);
}