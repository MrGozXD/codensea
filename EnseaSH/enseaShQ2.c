#include <unistd.h> // POSIX standard library for Unix system calls (read, write, etc.)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{

    while (1)
    {
        // Welcome message
        const char *welcomeMessage = "Welcome to ENSEA Tiny Shell. \n"
                                     "To quit, type 'exit'. \n";

        ssize_t bytesWritten = write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
        if (bytesWritten == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Prompt
        const char *prompt = "enseash % ";
        bytesWritten = write(STDOUT_FILENO, prompt, strlen(prompt));
        if (bytesWritten == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Read user input
        char command[BUFFER_SIZE];
        ssize_t bytesRead = read(STDIN_FILENO, command, BUFFER_SIZE);
        if (bytesRead == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Remove the newline character at the end of the input
        command[bytesRead - 1] = '\0';

        // Check if the user wants to quit
        if (strcmp(command, "exit") == 0 || strcmp(command, "\001") == 0 )
        {
            exit(EXIT_SUCCESS);
        }

        // Execute the command
        int status = system(command);
        if (status == -1)
        {
            perror("system");
            exit(EXIT_FAILURE);
        }
    }
}