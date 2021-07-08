// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{ 
    FILE *fp ;
    fp=fopen("./text.txt", "w");


    int fk = fork();
    if(fk < 0){
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if(fk == 0){
        printf("Child pid is %d\n", (int)getpid());
        char *child_str = "Child string aaaaaaaaaaaa\n";
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
    } else {
        // wait(NULL);
        printf("Parent pid is %d\n", (int)getpid());
        char *parent_str = "Parent string bbbbbbbbbbbb\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
        
    };
    fclose(fp);
    return 0;
}
