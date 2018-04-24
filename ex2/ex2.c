// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp;
    char str[40] = " It looks fun, let's see.\n";
    fp = fopen("text.txt", "w+");

    int rc =fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
       fwrite(str, sizeof(str),1, fp);  
       printf("hello, Child here \n");
    } else {
       // strcat(str, " I am at Parent!");
       char str[40] = "I am at Parent!";
        fwrite(str,sizeof(str), 1, fp);
        printf("hello, parent here\n");
    }
    fclose(fp);
    return 0;
}
/*
expected output:
hello, parent here
hello, Child here 
*/