// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp = fopen("text.txt", "w");
    int ptr = fork();
    if (ptr == 0)
    {
        char child[] = "Child";
        fwrite(child, 1, sizeof(child), fp);
    }
    else if (ptr > 0)
    {
        char parent[] = "Parent";
        fwrite(parent, 1, sizeof(parent), fp);
    }

    return 0;
}
