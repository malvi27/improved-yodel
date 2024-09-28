#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "myfifo_mkfifo"

void reader() {
    int fd;
    char buffer[100];

    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO for reading");
        exit(1);
    }
    read(fd, buffer, sizeof(buffer));
    printf("Reader read: %s\n", buffer);
    close(fd);
}

int main() {
    reader();
    return 0;
}

