// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently? Parent written before child and file is rewritten.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    fp = fopen("text.txt", "w+");

    int pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (pid == 0){
        fprintf(fp, "%s %d \n", "Vance", 654);
    }else {
        fprintf(fp, "%s %d \n", "Ronald", 362);
    }




    fclose(fp);

    return 0;
}
