#include <unistd.h> // POSIX standard library for Unix system calls (read, write, etc.)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 256


int main(int argc, char *argv[]) {
    
    const char *welcomeMessage="Welcome to ENSEA Tiny Shell. \n"
                              "To quit, type 'exit'. \n";
    
    ssize_t bytesWritten=write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
    if (bytesWritten==-1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    const char *prompt="enseash % ";
    bytesWritten=write(STDOUT_FILENO, prompt, strlen(prompt));
    if (bytesWritten==-1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

}