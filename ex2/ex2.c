// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("text.txt", "r+");
    int f = fork();
    int c;
    if (f < 0)
    {
        printf("Could not fork\n");
        exit(1);
    }
    if (f == 0)
    {
        fprintf(file, "\n%s %s", "Forked", "text");
        printf("Child fork created\n");
    }
    else
    {
        int wait = waitpid(f, NULL, 0);
        fprintf(file, "\n%s %s", "Parent", "section");
        printf("I'm the parent\n");
    }
    while (1)
    {
        c = fgetc(file);
        if (feof(file))
        {
            printf("\n");
            break;
        }
        printf("%c", c);
    }
    fclose(file);

    return 0;
}
