// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *file = fopen("text.txt", "r+");
    int c;
    printf("File pointer: %p\n", file);
    printf("Forking...\n");
    int child = fork();

    if (child < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        printf("\nFile pointer as child: %p\n", file);
        // Both processes can't write to the file
        /*printf("Attempting to write \'This is the child\' to the file as the child..\n");
        if (file != NULL)
        {
            fputs("hello world", file);
            fclose(file);
        }*/
        printf("Attempting to read the file as the child..\n");
        while (1)
        {
            c = fgetc(file);
            if (feof(file))
            {
                break;
            }
            printf("%c", c);
        }
    }
    else
    {
        printf("\nFile pointer as parent: %p\n", file);
        /*printf("Attempting to write \'This is the parent\' to the file as the child..\n");
        if (file != NULL)
        {
            fputs("hello world", file);
            fclose(file);
        }*/
        printf("Attempting to read the file as the parent..\n");
        while (1)
        {
            c = fgetc(file);
            if (feof(file))
            {
                break;
            }
            printf("%c", c);
        }
    }

    fclose(file);

    printf("\nCannot write to the file in both processes. Reading the file seems to only work in the parent.\n");
    return 0;
}
