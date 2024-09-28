#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_process_tree(int level, int max_level) {
    if (level > max_level) {
        return;
    }

    pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        // In child process 1
        printf("Child 1 created at level %d with PID %d, parent PID %d\n", level, getpid(), getppid());
        create_process_tree(level + 1, max_level);
        exit(0);
    } else {
        // In parent process
        // Create second child
        pid2 = fork();

        if (pid2 < 0) {
            // Fork failed
            perror("Fork failed");
            exit(1);
        } else if (pid2 == 0) {
            // In child process 2
            printf("Child 2 created at level %d with PID %d, parent PID %d\n", level, getpid(), getppid());
            create_process_tree(level + 1, max_level);
            exit(0);
        } else {
            // In parent process
            // Wait for both children to finish
            wait(NULL);
            wait(NULL);
        }
    }
}

int main() {
    int max_level = 3;  // Set the depth of the process tree
    printf("Parent process PID %d\n", getpid());
    create_process_tree(1, max_level);
    return 0;
}
