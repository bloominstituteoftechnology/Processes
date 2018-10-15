// The exec() system call is used in order to run a program that is different from
// the calling program (since fork only executes copies of the program that called it).
// Let's say we wanted to spin up a child process to execute a word count program.

// p3.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h> // this header file is needed in order to work with strings

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int)getpid());
    int rc = fork();
    // -------------- child process starts executing here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        printf("hello, child here (pid: %d) \n", (int)getpid());
        char *myargs[3]; // allocate an array of chars to hold 3 bytes
        // `strdup` duplicates the given input string
        // - handles malloc under the hood for the following strings
        // -  - allocating enough memory and writing this strings into it
        myargs[0] = strdup("wc");   // pass the name of the program we want to run as the first array element - 'word count'
        myargs[1] = strdup("p3.c"); // argument: the file to count
        myargs[2] = NULL;           // marks the end of the array
        // exec() - takes the process that called it and it transforms that process into a different one
        // f/e: when you type  'code .'  into terminal happens two things:
        // - a fork, followed by exec() on the child process
        // step 1 - it goes and clones the terminal (child process)
        // step 2 - calls the system call exec() where you tell exac what program you want this process to be transformed into
        // exec() wiil do the work of transforming this process into the one you specified
        execvp(myargs[0], myargs); // runs the word count program, passing in the `myargs` array to the word count program as arguments
        printf("this should not be seen");
    }
    else
    {
        int wc = waitpid(rc, NULL, 0); // `waitpid` call added here
        printf("hello, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
    }

    return 0;
}