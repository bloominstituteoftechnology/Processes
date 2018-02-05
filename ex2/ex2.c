// Write a program that opens the text.txt  file (with the `fopen()` system call)
// located in this directory
// and then calls `fork()` to create a new process.
// Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    FILE *fp;
    int rc = fork();
    fp = fopen("text.txt", "w");
    if (rc == 0)
    {
        printf("here 1 \n");
        char str1[] = "this is string 1";
        fwrite(str1, 1, sizeof(str1), fp);
    }
    else
    {
        printf("here 2 \n");
        char str2[] = "this is string 2";
        fwrite(str2, 1, sizeof(str2), fp);
    }
    fclose(fp);
    return 0;
}
