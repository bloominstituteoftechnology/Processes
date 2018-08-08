// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char data[140];
    printf("opening the file text.txt in read/write mode");
    fp = fopen("text.txt", "r+");
    if (fp == NULL){
        printf("Could not open text.txt");
        return 1;
    }
    
    printf("\n Enter some text to write into file text.txt:");
    while(strlen (gets( data )) > 0){
        fputs(data, fp);
        fputs("\n", fp);
    }
    printf("Closing the file text.txt");
    fclose(fp);
    return 0;
}
