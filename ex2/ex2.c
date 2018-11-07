// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
//they're both able to run on a single fopen. Interestingly, throwing an fclose at the end of either the if or else statement doesn't
//seem to do anything

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    fp = fopen("text.txt", "w+");
    int count = fork();
    if (count == 0)
    {
        fprintf(fp, "%s %s %s %s", "I", "can", "go", "anywhere\n");
        printf("child printed\n");
        fclose(fp);
    }
    else
    {
        fprintf(fp, "%f %f %s %s", 0.03, 5.57, "do", "anything\n");
        printf("parent printed\n");
        
    }
    ;

    return (0);
}
