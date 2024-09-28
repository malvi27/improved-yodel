#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

void orphan()
{
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) 
    {
        printf("Child process started and sleeping...\n");
        sleep(10);
        printf("Orphan Child PID %d \n", getpid());
        printf("Child Process terminated in orphan\n");
    } 
    else 
    {
        // Parent process
        printf("Parent process...\n");
        printf("Orphan Parent process PID: %d\n", getpid());
        printf("Parent Process terminated in orphan\n");
        exit(0);
    }
    

}

void zombie()
{
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) 
    {
        printf("Child process started...\n");
        printf("Zombie Child PID %d \n", getpid());
        printf("Child Process terminated from Zombie\n");
    } 
    else 
    {
        // Parent process
        printf("Parent process started and sleeping...\n");
        sleep(10);
        printf("Zombie Parent process PID: %d\n", getpid());
        printf("Parent Process terminated from Zombie\n");
        exit(0);
    }
}

int main() {
    zombie();
    orphan();
    return 0;
}
