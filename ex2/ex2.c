// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE * fp;

    fp = fopen("text.txt", "w+");
    int year = 2018;
    fprintf(fp, "%s %s %s %d\n", "We", "are", "in", year);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        year++;
        fprintf(fp, "hello, child here. I wish it was the year %d \n", year);
    }
    else {
        year--;
        fprintf(fp, "hello, parent here. I wish it was the year %d\n", year);
    }
    
    return 0;
}
