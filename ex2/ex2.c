// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



#define MAXCHAR 1000

int main(void)
{
    // Your code here 
    int rc = fork();
    
    FILE *fp;
    char *fileName = "text.txt";
    char str[MAXCHAR];

    fp = fopen(fileName, "r");
    

    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    if (fp == NULL) {
        printf("Could not open file %s", fileName);
        return 1;
    }

    while (fgets(str, MAXCHAR, fp) != NULL) {
        printf("%s \n", str);
    
    fclose(fp);
    return 0;
    }
}
