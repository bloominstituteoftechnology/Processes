// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *file;
    // int rc = fork(); Having fork here will overwrite th file
    file = fopen("text.txt", "w");
    if (file == NULL)
    {
        printf("Could not open text.txt");
        exit(1);
    }
    int fileNum;
    fileNum = fileno(file);
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
        fprintf(file, "Child: %s", txt);

        printf("Child descriptor: %d\n", fileNum);
    }
    else
    {
        char *txt = "Parent.";
        fprintf(file, "Child %s", txt);
        printf("Parent descriptor: %d\n", fileNum);
    }

    fclose(file);
    return 0;
}
