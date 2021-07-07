// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    int x = 100;
    FILE * fp;
    fp = fopen("text.txt", "w");
    int my_fork = fork();
    if (my_fork == 0) {
        fprintf(fp, "%s", "Child\n");
        printf("Child\n");
        fclose(fp);
    }
    else if (my_fork > 0) {
        fprintf(fp, "%s", "Parent\n");
        printf("Parent\n");
        fclose(fp);
    }

    return 0;
}
