// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here    
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, child here (pid: %d)\n", (int) getpid());
        char *myargs[3]; // Allocate an array of chars to hold 3 bytes
        // 'strdup' duplicates the given input string
        myargs[0] = strdup("/bin/ls"); // Pass the name of the program
        myargs[1] = strdup("ex4.c"); // argument: the file to ls to
        myargs[2] = NULL; // marks the end of the array, null terminator "\0"
        execvp(myargs[0], myargs);
        printf("this should not be seen");
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("hello, parent (pid: %d) of child %d\n", (int) getpid(), rc);
    }
    return 0;
}
