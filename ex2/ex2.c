// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Yes they can both access the file descriptor
// The text file writes both entries no problem one after another in new lines to the text file

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
    // Your code here
    FILE *fd;

    fd = fopen("text.txt", "w+");

    fprintf(fd, "%s %d\n", "Before the fork\n", getpid());

    pid_t process = fork();

    if (process == 0)
    {
        fprintf(fd, "%s %d\n", "The file opened child\n", getpid());
        fclose(fd);
    }
    else
    {
        fprintf(fd, "%s %d\n", "The file opened parent\n", getpid());
        fclose(fd);
    }

    fclose(fd);

    return 0;
}
