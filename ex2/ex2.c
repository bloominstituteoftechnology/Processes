// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

//Solutions from Anthony Catalfo

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * fp;
    fp = fopen ("text.txt", "w+");
    printf("Exercise 2 (pid: %d)\n", (int) getpid());
    int process = fork();
    // ------------------------------------------------ child process starts executing here
    if (process < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (process == 0) {    // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int) getpid());
        fprintf(fp, "%s %s %s", "We", "are", "in the child\n");
        fclose(fp);
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), process);
        fprintf(fp, "%s %s %s", "We", "are", "in the parent");
        fclose(fp);
    }

    return 0;

}