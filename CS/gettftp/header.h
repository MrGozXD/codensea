#include <unistd.h> // POSIX standard library for Unix system calls (read, write, etc.)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 512
#define MODE "octet"
#define RRQ 1
#define WRQ 2
#define DATA 3
#define ACK 4

void dispGetAddrInfoSucceeded(struct addrinfo *res);
void dispGetAddrInfoFailed(int result);
void dispGetNameInfoSucceeded(char *host, char *serv);
void dispGetNameInfoFailed(int result);
//void getInfoSucceeded(struct addrinfo *res, char *host, char *serv, int result);
void didSucceed(int result, char *command);
char *setBuffer(char const *file, char *mode, int RRQorWRQ);
char *setACKBuffer(int blockNumber);
char *getDataFromBuffer(char *buffer);
//void receivedData(char Opcode);
//void receivedACK(char Opcode);
void receivedDataOrACK(char Opcode);