// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp; //creates a pointer named fp 
    fp = fopen("./ex2/text.txt", "w"); //the text file is opened by calling fopen()
    int rc = fork(); // the fork is initialized as rc
    if (rc < 0) { // if the value of rc is less than 0
        fprintf(stderr, "fork failed\n"); //the fork fails and an error message is output
        exit(1); //the program is exited
    } else if (rc == 0) { //if the value of the fork equals 0
        fprintf(fp, "child pid: %d\n", (int) getpid()); //the child process ID is printed by calling getpid()
    } else { //if the value of rc is 1 or more
        fprintf(fp, "parent pid: %d, child pid: %d\n", (int) getpid(), rc); //both the parent and child process ids are printed
    }
    fclose(fp); //the file is closed
    return 0;
}

// Both the parent and child can access the file. They both write to it, without erasing what the other wrote.
