// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("text.txt", "r+");

    int y = fork();
    if (y == 0) {
        fprintf(fp, "Child response %s %s\n", "Child", "Here");
        printf("Child pid is %d\n", (int)getpid());
    } else {
        fprintf(fp, "Parent response %s %s\n", "Parent", "Here");
        printf("Parent pid is %d\n", (int)getpid());
    }

    fclose(fp);
    
    return 0;
}
