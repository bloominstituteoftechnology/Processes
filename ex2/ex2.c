// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
    // --> yes both can access the fd. Parent's fprintf output shows up on top in text.txt and then child's.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * fd;
    fd = fopen("text.txt", "r+");
    printf("File Descriptor: %d\n", fd);

    // int size = sizeof(fd);
    // int buffer[size];

    int rc = fork();

    if (rc < 0) {
        printf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(fd, "%s\n", "Child");
        printf("hello, child here (pid: %d, File Descriptor: %d)\n", (int) getpid(), fd);
    } else {
        fprintf(fd, "%s\n", "Parent");
        printf("hello, parent here (pid: %d, File Descriptor: %d) of child %d\n", (int) getpid(), fd, rc);
    }

    return 0;
}
