#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid=fork();
    if (pid==0)
    {
        printf("I'm Child!\n");
        exit (0);
    }
    else
    {
        wait(NULL);
        printf("I'm Parent!\n");
        printf("Child pid = %d\n", pid);
    }

    return 0;
}