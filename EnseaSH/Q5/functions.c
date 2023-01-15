#include "headerEnseaSh.h"

void dispMessage(char *message)
{
    ssize_t bytesWritten = write(STDOUT_FILENO, message, strlen(message));
    if (bytesWritten == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }
}

char *readUserInput()
{
    char *buffer = malloc(BUFFER_SIZE);
    ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
    if (bytesRead == -1)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[strcspn(buffer, "\n")] = 0; // remove the newline character at the end of the input
    return buffer;
}

void executeCommand(char *command)
{
    // check if the user wants to quit
    if (strcmp(command, "exit") == 0 || strcmp(command, "\00") == 0)
    {
        dispMessage(QUIT_MSG);
        exit(EXIT_SUCCESS);
    }

    // execute command in a child process
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
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
        int status;
        waitpid(pid, &status, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);
        int time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000; // time in ms
        char str[MAX_SHELL_MSG_SIZE];
        if (WIFEXITED(status))
        {
            sprintf(str, "enseaSH [exit : %d | %dms] %", status, time);
            write(STDOUT_FILENO, str, strlen(str));
        }
        else if (WIFSIGNALED(status))
        {
            sprintf(str, "enseaSH [signal : %d | %dms] %", status, time);
            write(STDOUT_FILENO, str, strlen(str));
        }
        else
        {

            sprintf(str, "enseaSH [unknown : %d | %dms] %", status, time);
            write(STDOUT_FILENO, str, strlen(str));strcat(str, " % ");
        }
    }
}