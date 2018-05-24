// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Your code here
    FILE *fp;
    fp = fopen("text.txt", "r+");

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child pid %d\n", (int)getpid());
        fprintf(fp, "This is from the child\n");

        //===== also
        // char *child_str = "This is child string\n";  // also char child_str[] = "This is child string\n";
        // fwrite(child_str, 1, strlen(child_str), fp); // 1 is for byte size.
    }
    else
    {
        printf("Parent pid %d\n", (int)getpid());
        fprintf(fp, "This is from the parent\n");
    }

    fclose(fp);

    return 0;
}
