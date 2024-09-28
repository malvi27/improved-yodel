#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[100];
    scanf("%s", write_msg);
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    // Fork the process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) 
    {
        close(fd[0]);
        write(fd[1], write_msg, strlen(write_msg) + 1);
        printf("Child wrote %ld bytes. It wrote %s to the pipe.\n", strlen(write_msg), write_msg);
        close(fd[1]);
    } 
    else 
    {
        wait();
        close(fd[1]); 
        read(fd[0], read_msg, sizeof(read_msg)); 
        close(fd[0]); 
        printf("Parent read %ld bytes. It read %s from the pipe.\n", strlen(read_msg), read_msg);
    }

    return 0;
}
