#include "header.h"

void dispGetAddrInfoFailed(int result)
{
    const char *errorMessage = gai_strerror(result);
    printf("Error: getaddrinfo failed\n");
    printf("Error message: %s\n", errorMessage);
    exit(1);
}

void dispGetAddrInfoSucceeded(struct addrinfo *res)
{
    struct addrinfo *tmp;
    for (tmp = res; tmp != NULL; tmp = tmp->ai_next)
    {
        printf("Success: getaddrinfo succeeded\n");
        printf("res->ai_family: %d\n", tmp->ai_family);
        printf("res->ai_socktype: %d\n", tmp->ai_socktype);
        printf("res->ai_protocol: %d\n", tmp->ai_protocol);
        printf("res->ai_addrlen: %d\n", tmp->ai_addrlen);
        printf("res->ai_addr: %s\n", tmp->ai_addr);
        printf("res->ai_canonname: %s\n", tmp->ai_canonname);
        printf("res->ai_flags: %d\n", tmp->ai_flags);
        printf("res->ai_next: %s\n", tmp->ai_next);
    
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
    const char *errorMessageNameInfo = gai_strerror(result);
    printf("Error: getnameinfo failed\n");
    printf("Error message: %s\n", errorMessageNameInfo);
    exit(1);
}

void didSucceed(int result, char *command)
{
    if (result == -1)
    {
        printf("Error: %s failed\n", command);
        exit(1);
    }
    else
    {
        printf("Success: %s succeeded\n", command);
    }
}

char *setBuffer(char const*file, char *mode, int RRQorWRQ)
{
    /*
    int count = 0;
    char buffer[BUFFER_SIZE];
    buffer[count++]=0;
    buffer[count++]=1;
    strcpy(&buffer[count], file);
    count+=strlen(file);
    buffer[count]=0;

    strcpy(&buffer[count+1],mode);
    count+=strlen(mode)+1;
    buffer[count]=0;

    for (int i = 0; i < count+1; i++)
    {
        printf("buffer[%d]: %d\n", i, buffer[i]);
    }
    printf("count: %d\n", count);
    */
    char *buffer = (char *)malloc(BUFFER_SIZE);

    buffer[0] = 0;
    buffer[1] = RRQorWRQ;
    strcpy(buffer + 2, file);
    strcpy(buffer + 2 + strlen(file) + 1, MODE);

    // debug function
    for (int i = 0; i < (int)strlen(file) + 9; i++)
    {
        printf("buffer[%d]: %d\n", i, buffer[i]);
    }
    printf("strlen(buffer): %d\n", strlen(buffer));

    return buffer;
}