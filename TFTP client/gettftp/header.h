#include <unistd.h> // POSIX standard library for Unix system calls (read, write, etc.)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BLOCK_SIZE 512
#define BUFFER_SIZE 256
#define MAX_SHELL_MSG_SIZE 128


void dispGetAddrInfoFailed(int result);
void dispGetAddrInfoSucceeded(struct addrinfo *res);
void dispGetNameInfoSucceeded(char *host, char *serv);
void dispGetNameInfoFailed(int result);
void didSucceed(int result, char *command);