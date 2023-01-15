#include <unistd.h> // POSIX standard library for Unix system calls (read, write, etc.)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
#define MAX_SHELL_MSG_SIZE 128

// TODO : Refactor as question 3 (exit/ctrl+d) , remove time.h and methods

int main(int argc, char *argv[])
{
    const char *welcomeMessage = "Welcome to ENSEA Tiny Shell. \n"
                                 "To quit, type 'exit'. \n";
    const char *prompt = "enseash % ";
    const char *exitMessage = "Bye bye! \n";

    char *shellmsg = malloc(MAX_SHELL_MSG_SIZE);
    char *previousCommandExitStatus = malloc(MAX_SHELL_MSG_SIZE / 4);
    // shellmsg="";
    char command[BUFFER_SIZE];
    int previousCommandIsExit = 0;
    int previousCommandIsSignal = 0;
    char *previousCommandNumberStatus = malloc(10);

    // Welcome message
    ssize_t bytesWritten = write(STDOUT_FILENO, welcomeMessage, strlen(welcomeMessage));
    if (bytesWritten == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    bytesWritten = write(STDOUT_FILENO, prompt, strlen(prompt));
    if (bytesWritten == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    while (1)
    {

        // clear command[] buffer
        memset(command, 0, BUFFER_SIZE);

        // Read user input

        ssize_t bytesRead = read(STDIN_FILENO, command, BUFFER_SIZE);
        if (bytesRead == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Remove the newline character at the end of the input
        //  command[bytesRead - 1] = '\0'; !! this is not working, it doesn't cover the case command="\0" !!
        command[strcspn(command, "\n")] = 0;

        // Check if the user wants to quit

        if (strcmp(command, "exit") == 0 || strcmp(command, "\0") == 0)
        {
            ssize_t bytesWritten2 = write(STDOUT_FILENO, exitMessage, strlen(exitMessage));
            if (bytesWritten2 == -1)
            {
                perror("write");
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        }

        // Execute the command with execlp in a child process

        int status;
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // child process
            status = execlp(command, command, NULL); // execlp écrase le reste du code, plus rien n'est exécuté après

            if (status == -1)
            {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // parent process
            wait(&status);
            char str[100];
            clock_gettime(CLOCK_MONOTONIC, &end);
            if (WIFEXITED(status))
            {
                sprintf(str, "enseaSH [exit : %d]", status);
                strcat(str, " % ");
                write(STDOUT_FILENO, str, strlen(str));
            }
            else if (WIFSIGNALED(status))
            {
                sprintf(str, "enseaSH [signal : %d]", status);
                strcat(str, " % ");
                write(STDOUT_FILENO, str, strlen(str));
            }
            else
            {
                sprintf(str, "enseaSH [unknown : %d]", status);
                strcat(str, " % ");
                write(STDOUT_FILENO, str, strlen(str));
            }

            /*
            previousCommandIsExit = WIFEXITED(status);
            previousCommandIsSignal = WIFSIGNALED(status);
            if(previousCommandIsExit){
                previousCommandExitStatus = "exit : ";
                int a=sprintf(previousCommandNumberStatus, "%d", WEXITSTATUS(status));
                previousCommandExitStatus = strcat(previousCommandExitStatus, previousCommandNumberStatus);
            }
            else if(previousCommandIsSignal){
                previousCommandExitStatus = "signal: ";
                int a=sprintf(previousCommandNumberStatus, "%d", WTERMSIG(status));
                previousCommandExitStatus = strcat(previousCommandExitStatus, previousCommandNumberStatus);
            }
            else{
                previousCommandExitStatus = "unknown ";
            }
            */
        }
    }
}