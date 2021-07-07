// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("./text.txt", "w");
    // the w in this will reset the file everytime (at least that is what documentation says)
    if(file == NULL){
        printf("The file was not opened!");
    }
    // Above if statement will print if file was not opened 

    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
        fprintf(file, "Hello world!!!");
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        fprintf(file, "Hello world!!!");
    }
    
    return 0;
}

// two hello worlds appear in the file one when rc == 0 and another in the else statement