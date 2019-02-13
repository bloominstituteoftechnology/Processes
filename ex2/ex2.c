// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE = *f;
    f = fopen("text.txt", "r");
    int n = fork();

    if (n == 0)
    {
        printf("child");
    }
    else if (n > 0)
    {
        printf("parent");
    }
    return 0;
}
