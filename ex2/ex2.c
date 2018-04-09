// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int num;
    FILE *fp;
    fp = fopen("text.txt", "w");

    if(fp == NULL) {
        printf("Process failed.");
        exit(1);
    }

    int rc = fork();
    if (rc == 0) {
        printf("Hello!\n");
        printf("Enter a number: ");
        scanf("%d",&num);
        fprintf(fp, "%d", num);
        fclose(fp);
    } else {
        waitpid(rc, NULL, 0);
        printf("Enter a number: ");
        scanf("%d", &num);
        fprintf(fp, "%d", num);
        fclose(fp);
        printf("Goodbye!\n");
    }
    return 0;
}
