// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // Must include to use strlen()

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt", "w"); 

    int rc = fork(); 
    if (rc < 0) {
        fprintf(stderr, "fork failed\n"); 
        exit(1); 
    }
    else if (rc == 0) {
        printf("\nChild process has been executed."); 
        char *child_str = "I am the child process!\n"; 
        fwrite(child_str, sizeof(char), strlen(child_str), fp); 
    }
    else {
        printf("Parent process has been executed."); 
        char *parent_str = "I am a parent process!\n"; 
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp); 
    }
    fclose(fp); 
    return 0;
}
