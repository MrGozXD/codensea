#include <unistd.h> // POSIX standard library for Unix system calls (read, write, etc.)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

#define BUFFER_SIZE 256
#define MAX_SHELL_MSG_SIZE 128


void dispMessage(char * message);
char *readUserInput();