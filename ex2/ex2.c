// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
    // Your code here
    FILE *fd;

    fd = fopen("text.txt", "w+");
    
    fprintf(fd, "%s %d", "Before", getpid());

    pid_t process = fork();

    if (process == 0)
    {
        printf("The file opened child\n");
        fclose(fd);
    }
    else
    {
        printf("The file opened parent\n");
        fclose(fd);
    }

    return 0;
}
