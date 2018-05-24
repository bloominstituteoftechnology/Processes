// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *o;
    o = fopen("text.txt", "w");
   /*  if (o == NULL);
    {
        fprintf(stderr, "Error Opening file\n");
        exit(1);
    } */
    int chfork = fork();
    if (chfork < 0)
    {
        fprintf(stderr, "Fork Unsuccessful.\n");
        exit(1);
    }
    else if (chfork == 0)
    {
        printf("Child process.\n");
        char child[] = "Child String.\n";
        fwrite(child, 1, sizeof(child), o);
    }
    else
    {
        printf("Parent process.\n");
        char parent[] = "Parent String.\n";
        fwrite(parent, 1, sizeof(parent), o);
    }
    fclose(o);
    return 0;
}
