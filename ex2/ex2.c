// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "w");

    int rc = fork();
    if(rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if(rc == 0)
    {
        printf("Child process here\n");
        char *child_str = "This is a child string.\n";
        fwrite(child_str, sizeof(child_str), strlen(child_str), fp);
    } else
    {
        printf("Parent process here\n");
        char *parent_str = "This is parent string!\n";
        fwrite(parent_str, sizeof(parent_str), strlen(parent_str), fp);
    }
}
