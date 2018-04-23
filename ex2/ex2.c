// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory

// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor

// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    FILE *fp;

    fp = fopen("text.txt", "w+");

    int process = fork();

    if (process == 0)
    {
        printf("Child process PID - (pid: %d) \n", (int)getpid());
    }

    else if (process > 0)
    {
        printf("Parent process PID - (pid: %d) \n", (int)getpid());
    }

    else
    {
        fprintf(stderr, "fork failed \n");
        exit(1);
    }

    fprintf(fp, "%s %s %s %s", "My", "name", "is", "Dixie");

    fclose(fp);
    
    return 0;
}