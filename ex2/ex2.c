// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    /// Your code here
    printf("hello world (pid: %d)\n", (int) getpid());
    FILE * fp;
    FILE * fp2;
    fp = fopen("/Users/samar/code/c/Processes/ex2/text.txt", "r");
    fp2 = fopen ("/Users/samar/code/c/Processes/ex2/text.txt", "w+");
    int c;
    int x = 100;
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        fprintf(fp2, "%s %s %s %d", "We", "are", "in", 2012);
        fclose(fp2);

        while(1) {
            c = fgetc(fp);
            if( feof(fp) ) { 
                break ;
            }
            printf("yo1 - %c\n", c);
        }

        fclose(fp);
        printf("hello, child here (pid: %d) \n", (int) getpid());
    } else {

        fprintf(fp2, "%s %s %s %d", "We", "are", "in", 2018);
        fclose(fp2);

        while(1) {
            c = fgetc(fp);
            if( feof(fp) ) { 
                break ;
            }
            printf("yo2 - %c\n", c);
        }
        fclose(fp);
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}


//when trying to access stream from child - operation gets stuck at something. 
// while accessing stream from parent - everything works out smoothly!


//when trying to read concurrently only child reads



//when trying to write and read just in child - everthing works as expected except it's still not reaching end of execution


//when trying to write both parent and child -only child is read and , eof is not reached