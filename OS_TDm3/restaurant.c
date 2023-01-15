#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Defined in netdb.h

/*
struct addrinfo{
    int ai_flags; // AI_PASSIVE, AI_CANONNAME, etc.
    int ai_family; // AF_INET, AF_INET6, AF_UNSPEC
    int ai_socktype; // SOCK_STREAM, SOCK_DGRAM
    int ai_protocol; // use 0 for "any"
    socklen_t ai_addrlen; // size of ai_addr in bytes
    struct sockaddr *ai_addr; // struct sockaddr_in or _in6
    char *ai_canonname; // full canonical hostname
    struct addrinfo *ai_next; // linked list, next node
};

int getaddrinfo(const char *node, const char *service, const addrinfo *hints, addrinfo **res)
{
    // node: hostname or IP address
    // service: service name or port number NULL=
    // hints: hints about socket type
    // res: linked list of addrinfo results
}

void freeaddrinfo(addrinfo *res)
{
    // free the linked list
}

int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host, size_t hostlen, char *serv, size_t servlen, int flags)
{
    // sa: socket address
    // salen: length of sa
    // host: hostname
    // hostlen: length of host
    // serv: service name
    // servlen: length of serv
    // flags: NI_NUMERICHOST, NI_NUMERICSERV, etc.
}

*/

#define BUFFER_SIZE 256

int main(int argc, char const *argv[])
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_protocol=IPPROTO_TCP; 
   
    struct addrinfo *res,*tmp;

    int result=getaddrinfo(argv[1], argv[2], &hints, &res);
    
    // remark: will never fail cause DNS sends back to ucopia.ensea.fr
    if (result != 0)
    {
        const char *errorMessage=gai_strerror(result);
        printf("Error: getaddrinfo failed\n");
        printf("Error message: %s\n", errorMessage);
        exit(1);
    }
    else
    {
        for (tmp = res; tmp!=NULL; tmp=tmp->ai_next){
            printf("Success: getaddrinfo succeeded\n");
            printf("res->ai_family: %d\n", tmp->ai_family);
            printf("res->ai_socktype: %d\n", tmp->ai_socktype);
            printf("res->ai_protocol: %d\n", tmp->ai_protocol);
        }
    }


    char host[BUFFER_SIZE];
    char serv[BUFFER_SIZE];

    int name=getnameinfo(res->ai_addr, res->ai_addrlen, host, sizeof(host), serv, sizeof(serv), NI_NUMERICHOST|NI_NUMERICSERV);
    
    if (name != 0)
    {
        const char *errorMessageNameInfo=gai_strerror(name);
        printf("Error: getnameinfo failed\n");
        printf("Error message: %s\n", errorMessageNameInfo);
        exit(1);
    }
    else
    {
        printf("Success: getnameinfo succeeded\n");
        printf("host :%s\n", host);
        printf("serv :%s\n", serv);
    }
    return 0;
}
