#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void print_PCB()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    uid_t uid = getuid();
    gid_t gid = getgid();

    printf("PID: %d, PPID: %d, UID: %d, GID: %d \n", pid, ppid, uid, gid);
}

int main()
{
    // Q1.1 and Q1.2
    /*
    pid_t ret=fork();
    if(ret==0)
    {
        printf("Yo it's child process\n");
    }
    else
    {
        printf("Yo it's parent process, fork() returned: %d \n",ret);
    }

    //printf("fork() returned %d\n", ret);
    print_PCB();
    exit(EXIT_SUCCESS);
    */

    // Q1.3
    /*
    fork();fork();fork(); // 8 processes = 2^3 processes (3 forks)
    printf("fork!\n");
    exit(EXIT_SUCCESS);
    */

   // Q2.1
    /*
   while (1)
   {
    fork();
    printf("fork!\n");
   }
   */

  // Q2.2
  /*
  while (1)
  {
    int pid=fork();

    if(pid<0) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    }
    else if(pid==0) { // This is a child process
        sleep(3);
        exit(EXIT_SUCCESS);
    }
    
    // If this is the parent process => continue the loop to create more child processes
  }
    printf("This is the end of the program");
    exit(EXIT_SUCCESS);
    */
    // in a terminal : 
    // man 2 fork : gives me ERRORS, in this case it's EAGAIN, A system-imposed limit on the number of threads was encountered. 
    // ulimit -a : gives me the limits of the system (number of processes, number of files, etc.). At line -u, it says 31243, which is the maximum number of processes that can be created.

    // Q3.1

    while (1)
    {
        int pid=fork();

        if(pid<0) {
            perror("fork() failed");
            exit(EXIT_FAILURE);
        }
        else if(pid==0) { // This is a child process
            sleep(10);
            // return to parent process
            exit(EXIT_SUCCESS);
        }
        // This is the parent process
        // Wait for the child process to return
        wait(NULL); // NULL means that we don't care about the status of the child process
        printf("The child process has returned\n");
    }

    /*
    a) When the child process exits normally, it returns a status code of 0 to the parent process. This indicates that the child process completed successfully without any errors.

b) If the child process is killed prematurely using a signal, the status returned to the parent process will depend on the specific signal used to kill the child. For example, if the child is killed using the SIGKILL signal, the status returned will be a value of 128 plus the signal number (in this case, 128 + 9 = 137).

c) If the parent process does not wait for the child process to return, and the child process is terminated prematurely, the child process will become a "zombie" process. This means that the child process will still exist in the system, but it will be in a "zombie" state, occupying system resources without actually doing any work.

d) If the parent process is killed prematurely, the child process will continue to run unless it is also terminated. If the child process is not terminated, it will become a "orphan" process, which means that it will not have a parent process to wait for it or manage its resources. In this case, the orphan process will be adopted by the init process, which is the parent process of all processes on the system.
    
    #include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    // Create a child process
    pid_t pid = fork();

    if (pid == 0)
    {
        // This is the child process.
        // Sleep for 10 seconds
        sleep(10);

        // Return normally
        return 0;
    }
    else if (pid > 0)
    {
        // This is the parent process.
        // Wait for the child process to return
        int status;
        wait(&status);

        // Print the child's return status
        printf("Child process returned with status %d\n", status);

        // Kill the child process using the SIGKILL signal
        kill(pid, SIGKILL);

        // Wait for the child process to return after being killed
        wait(&status);

        // Print the child's return status after being killed
        printf("Child process returned with status %d after being killed\n", status);

        // Don't wait for the child process to return
        // The child process will become a zombie
        printf("Child process is now a zombie\n");

        return 0;
    }
    else
    {
        // There was an error creating the child process
        printf("Error creating child process\n");

        return 1;
    }
}

    
    */

}