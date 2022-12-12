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
        const char *prompt = "enseash % \n";
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
        const char *exitMessage="Bye bye! \n";
        

        if (strcmp(command, "exit") == 0)
        {
            ssize_t bytesWritten2=write(STDOUT_FILENO, exitMessage, strlen(exitMessage));
            if (bytesWritten2==-1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        }
        

        // execute the command with execlp and fork it
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // child process
            int status = execlp(command, command, NULL);
            if (status == -1)
            {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // parent process

        }
    }
}