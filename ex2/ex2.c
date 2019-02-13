// Write a program that opens the text.txt file (with the `fopen()` library call) 
//located in this directory 
// and then calls `fork()` to create a new process. 
// Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // opens the text.txt file (with the `fopen()` library call)
    FILE* fp; //file pointer
    fp = fopen("text.txt","r"); // parent process - read this file 

    
    int rc = fork(); // rc: return code

    // ------------------------------------------------ child process starts executing here
     if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");//prints to standard error 
        exit(1);

    } else if (rc == 0) {    // child process satisfies this branch
        fp = fopen("text.txt","a");// open text.txt appends content to file
        fprintf(fp, "%s %s %s %d", "We", "are", "in", 2019);
        fclose(fp); 
        printf("hello, child here (pid: %d) \n", (int) getpid());

    } else {
        fp = fopen("text.txt","a");// open text.txt appends different content to file
        fprintf(fp, "%s %s %s %d", "We", "are", "in", 2020);
        fclose(fp); 
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    
    return 0;
}
