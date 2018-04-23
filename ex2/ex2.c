// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *file = fopen("text.txt", "ab+");
    int new_fork = fork();
    if (new_fork < 0) {
        printf("Fork failure!\n");
    } else if (new_fork == 0) {
        char *msg = "Child process is writing to the file\n";
        printf("New process forked. PID is %d\n", getpid());
        fwrite(msg, strlen(msg), 1, file);
    } else {
        char *msg = "Parent process writing to the file here\n";
        printf("Parent process with PID: %d\n", getpid());
        fwrite(msg, strlen(msg), 1, file);
    }
    fclose(file);

    return 0;
}
