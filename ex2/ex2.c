// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. 
//Can both the child and parent access the file descriptor returned by `fopen()`? yes
//What happens when they are written to the file concurrently? both streams are added to the file.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("text.txt", "w");
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if ( rc == 0) {
        fprintf(fp,"%s %s %s %s (pid:%d)\n", "I", "am", "the", "child", (int) getpid());
    } else {
        fprintf(fp,"%s %s %s %s (pid:%d) %s %s (pid:%d)\n", "I", "am", "the", "parent", (int) getpid(), "of", "child", rc);
    }
    fclose(fp);
    return 0;
}
