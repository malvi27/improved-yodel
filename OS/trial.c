#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2], n;
    char buffer[100];
    pipe(fd);

    if (fork() > 0) {
        wait();
        n = read(fd[0], buffer, sizeof(buffer));
        write(1, buffer, n);
        printf("Parent read %d bytes\n", n);// Parent process
        
    } else {  // Child process
        char message[] = "hello\n";
        n = write(fd[1], message, strlen(message));
        printf("Child wrote %d bytes\n", n);
    }

    return 0;
}