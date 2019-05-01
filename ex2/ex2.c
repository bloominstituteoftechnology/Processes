// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// It doesnt seem that the both the child and parent can access the textfile.


//https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    char c;
    FILE *fp;
    printf("Opening the file text.txt to read\n");

    fp = fopen("text.txt", "r\n");    

    // if (fp == NULL)
    // {
    //     printf("Could not open text.txt");
    //     return 1;
    // } else {
    //     while ((c = getc(fp)) != EOF)
    //         //putchar(c);
    //         printf("%c", c);
    //         // printf("\n");
    //     fclose(fp);
    // }

    // so it prints parent fork, then child fork, but prints the
    // textfile from parent fork?
    int text_fork = fork();
    if (text_fork < 0)
    {
        printf("fork failed\n");
        exit(1);
    } else if (text_fork == 0)
    {
        printf("child fork \n");
        while ((c = getc(fp)) != EOF)
            printf("%c", c);
        fclose(fp);
    } else
    {
        printf("parent fork \n");
        while ((c = getc(fp)) != EOF)
            printf("%c", c);
        fclose(fp);
    }
    
    return 0;
}
