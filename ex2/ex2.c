// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    pid_t pid = fork();
    FILE *fp;
    fp = fopen("text.txt", "w+");

    if (pid == 0)
    {

        fprintf(fp, "\n I\'m printing from the child\n");
        exit(1);
    }
    else
    {
        fprintf(fp, "\n I\'m printing from the parent\n");
    }

    return 0;
}

// oddly enough only the child printed in my code.. did I do something wrong?