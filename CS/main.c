#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    if (fork()==0)
    {
        if (fork()!=0)
        {
            printf("A");
        }
        printf("B");
    }
    else
    {
        wait(NULL);
        printf("C\n");
        exit(0);
    }
    printf("D");
}