// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    char c;
    FILE *fp;
    printf("Opening the file text.txt to read\n");

    fp = fopen("text.txt", "r");

    if (fp == NULL)
    {
        printf("Could not open text.txt");
        return 1;
    } else {
        while ((c = getc(fp)) != EOF)
            //putchar(c);
            printf("%c", c);
            // printf("\n");
        fclose(fp);
    }
    
    return 0;
}
