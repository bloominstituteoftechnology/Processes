// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0)
    {
        printf("Child process\n");
        char *child_str = "Child string.\n";
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
        fclose(fp);
    }
    else
    {
        printf("Parent process\n");
        char *parent_str = "Parent string.\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
        fclose(fp);
    }
    return 0;
}
