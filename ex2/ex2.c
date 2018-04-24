// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *fp;

    fp = fopen("./text.txt", "w+");

    int cp = fork();
    // ----------------------------------------------- child process starts here
    
    if (cp < 0) { // fork failed, exit
        fprintf(stderr, "fork faild\n");
        exit(1);
    } else if (cp == 0) { // child process successfully created
        printf("hello, child process (pid: %d)\n", (int) getpid());
        char *child_str = "hello child string!\n";
        fprintf(fp, child_str);
    } else {
        printf("hello, parent process (pid: %d)\n", (int) getpid());
        char *parent_str = "hello parent string!\n";
        fprintf(fp, parent_str);
    }

    fclose(fp);

    return 0;
}
