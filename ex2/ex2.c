// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this 
//directory 
// and then calls `fork()` to create a new process. 
//Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    // char data[140];
    printf("opening the file text.txt in read/write mode");
    fp = fopen("text.txt", "r+");
    if (fp == NULL){
        printf("Could not open text.txt");
        return 1;
    }
    
    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        printf("\nFork process child...\n");
        char *fileStr1 = "Take a sad song and make it better...\n";
        fwrite(fileStr1, 1, strlen(fileStr1), fp);
    }
    else {
        printf("\nParent process...\n");
        char *fileStr2 = "Hey, Jude...Don't make it bad...\n";
        fwrite(fileStr2, 1, strlen(fileStr2), fp);
    }
    // printf("\n Enter some text to write into file text.txt:\n");
    // while(strlen(gets(data))> 0){
    //     fputs(data, fp);
    //     fputs("\n", fp);
    // }
    
    
    printf("Closing the file text.txt\n");
    fclose(fp);
    return 0;
}
