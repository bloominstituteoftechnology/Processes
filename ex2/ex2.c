// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char *argv[])
{
    // Your code here
    FILE *file = fopen("abc.txt", "r");
    int f = fork();
    if (file != NULL)
    {
        char *line;
        long unsigned int line_length = 0;
        while (getline(&line, &line_length, file) != -1)
        {
            if (f < 0)
                printf("something bad happened");
            else if (f == 0)
                printf("From child: %s", line);
            else
                printf("From parent: %s", line);
        }
        fclose(file);
    }

    FILE *file2 = fopen("text.txt", "w");
    if (file2 != NULL)
    {
        if (f < 0)
            printf("something bad happened");
        else if (f == 0)
            fprintf(file2, "File write from child");
        else
            fprintf(file2, "File write from parent");
    }
    fclose(file2);
    return 0;
}
