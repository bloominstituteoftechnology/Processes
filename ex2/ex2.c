// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "r+");
    pid_t pid = fork();
    if(pid == 0){
        fprintf(fp, "Hello World from the child\n");
        printf("Done writing to child\n");
    }else{
        fprintf(fp, "Hello World from the parent\n");
        printf("Done writing to parent\n");
    }
    printf("closing file\n");
    fclose(fp);
    
    return 0;
}
