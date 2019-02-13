// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

/*
Ok interesting stuff. I would like to talk to Sean more about this tomorrow. So I found that they have the same
file descriptor and pointer. I also found that you can overwrite the file depending where the fork is in the file.
I am not really sure what the hope was to see for the second question.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;
    // int rc = fork(); Having fork here will overwrite th file
    fp = fopen("text.txt", "w");
    if (fp == NULL)
    {
        printf("Could not open the file for text.txt");
        exit(1);
    }
    int fileNum;
    fileNum = fileno(fp);
    printf("Pointer: %d\n", fileNum);

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        char *txt = "Child.";
        fprintf(fp, "Look it is %s", txt);

        printf("Child descriptor: %d\n", fileNum);
    }
    else
    {
        char *txt = "Parent.";
        fprintf(fp, "Look it is %s", txt);
        printf("Parent descriptor: %d\n", fileNum);
    }

    fclose(fp);
    return 0;
}
