// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("./text.txt", "w");
    int child = fork();
    if (child == 0)
    {
        char str[] = "Child\n";
        fwrite(str, 1, sizeof(str), fp);
    }
    else
    {
        char str[] = "Parent\n";
        fwrite(str, 1, sizeof(str), fp);
    }
    fclose(fp);
    return 0;
}
