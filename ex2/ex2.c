// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE *f;
    f = fopen("text.txt", "w");

    int rc = fork();

    if( rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc == 0) {
        printf("Child pid: %d \n", (int)getpid());
        char *str = "String\n";
        fwrite(str, sizeof(char), strlen(str), f);
    }
    else {
        printf("Parent pid: %d\n", (int) getpid());
        char *pstr = "Parent string\n";
        fwrite(pstr, sizeof(char), strlen(pstr), f);
    }

    fclose(f);
    return 0;
}
