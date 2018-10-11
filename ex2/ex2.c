// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;
    file = fopen("text.txt", "r+"); 
    
    printf("Parent process, pid is %d\n", getpid());
    int pid = fork();
    
     if (pid < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        fprintf(file, "%s: %d\n", "Child process", getpid());
    }
    else
    {
        fprintf(file, "%s\n", "Parent process again");
    }
    fclose(file);
    return 0;
}
