#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "myfifo_mkfifo"

void create_fifo() {
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("Error creating FIFO with mkfifo");
        exit(1);
    }
}

void writer() {
    int fd;
    char message[50];
    getchar();

    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO for writing");
        exit(1);
    }

    write(fd, message, strlen(message) + 1);
    printf("Writer wrote:` %s ` to Fifo\n", message);
    close(fd);
}

int main() {
    create_fifo();
    writer();
    return 0;
}
