// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> 

int main(void)
{
     FILE *fp;
    
    printf("opening the file text.txt");
    fp = fopen("text.txt", "r+");
    if (fp == NULL){
        printf("could not open text.txt");
        return 1;
    }
    
    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        printf("\nfork process child...\n");
        char *fileStr1 = "whatever...\n";
        fwrite(fileStr1, 1, strlen(fileStr1), fp);
    }
    else {
        printf("\nparent process...\n");
        char *fileStr2 = "whatever again, hey hey hey, c...\n";
        fwrite(fileStr2, 1, strlen(fileStr2), fp);
    }
    
    printf("closing the file text.txt\n");
    fclose(fp);
    return 0;
}
