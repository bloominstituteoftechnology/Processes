// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
//they're both able to run 

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
        fprintf(fp, "%s %s %s %s", "I", "can", "go", "anywhere");
        printf("child printed\n");
    }
    else
    {
        fprintf(fp, "%f %f %s %s", 0.03, 5.57, "do", "anything");
        printf("parent printed\n");
        fclose(fp);
    }
    ;

    return (0);
}
