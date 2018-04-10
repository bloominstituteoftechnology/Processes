// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    fp = fopen("text.txt", "w");

    int child = fork();
    if(child < 0)
    {
        fprintf(stderr, "Fork has failed\n");
        exit(1);
    } else if(child == 0)
    {
        printf("This is the child process\n");
        char *child_str = "Child string\n";
        fwrite(child_str, 1, strlen(child_str), fp);
    } else 
    {
        printf("This is the parent process\n");
        char *parent_str = "Parent string\n";
        fwrite(parent_str, 1, strlen(parent_str), fp);
    }
    
    fclose(fp);
    return 0;
}
