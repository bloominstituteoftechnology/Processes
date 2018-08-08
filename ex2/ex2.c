// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    printf("In progress: open text.txt in read/write");
    fp = fopen("text.txt", "r+");
    
    if (fp == NULL) {
        printf("File will not open");
        return 1;
    }

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Failure to fork\n");
        exit(1);
    } else if (rc == 0) {
        printf("Forking child\n");
        char *fileStr1 = "but perfect practice does.\n";
        fwrite(fileStr1, 1, strlen(fileStr1), fp);
    } else {
        printf("\nProcessing parent\n");
        char *fileStr2 = "Practice does not lead to perfection, \n";
        fwrite(fileStr2, 1, strlen(fileStr2), fp);
    }
    
    printf("The file will now close.");
    fclose(fp);
    return 0;
}
