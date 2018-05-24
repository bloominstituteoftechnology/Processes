// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h> // this header is needed to work with strings

int main(int argc, char* argv[])
{
    // Your code here  
    printf("hello world (pid: %d)\n", getpid());

    // calling the fork
    int rc = fork();

    // child process starts here  
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        // child process satisfies this branch
        printf("Hello, child here (pid: %d) \n", (int) getpid());

        // allocate an array of chars to hold 3 bytes
        char *myargs[3];

        // `strdup` duplicates the given input string
        myargs[0] = strdup("wc"); // pass the name of the program we want to run as the first array element
        myargs[1] = strdup("ex4/f4.txt"); // argument: the file to count
        myargs[2] = NULL; // marks the end of the array

        // runs the word count program,passing in the `myargs` array to the word count program as arguments
        execvp(myargs[0], myargs);

        // doesn't reach here because a whole new program replaces this script
        printf("This should not be seen\n");
    } else {
        int wc = waitpid(rc, NULL, 0); // waitpid call added here
        printf("Hello. parent here (pid: %d) of child %d\n", getpid(), rc);
    }

    return 0;
}
