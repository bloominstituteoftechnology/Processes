// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    // Your code here    
    printf("Hello world! I am the parent process. I will go ahead and create a child process."); 
    int rc = fork(); 
    if (rc < 0) {
        fprintf(stderr, "Fork Failed"); 
        exit(1); 
    }
    else if (rc == 0) {
        printf("\nHello world! I am the child process. I will go ahead and execute a different program."); 
        char *myargs[3]; // allocate an array of chars to hold 3 bytes 
        // strdup duplicates the given input string 
        myargs[0] = strdup("ls"); // pass the name of the program we want to run as the first array element
        myargs[1] = strdup("-l"); // pass -l argument to display a long listing format for the program 
        myargs[2] = strdup("ex4.c"); // argument: the file to list
        myargs[3] = NULL; // marks the end of the array 
        execvp(myargs[0], myargs); // runs the list directory content program, passing in the myargs array to the word count program as arguments
        printf("\nThis should not be seen."); 
    }
    else {
        waitpid(rc, NULL, 0); // waitpid call added here
        printf("\nHello world! I am the parent process. My child process and the program it executed have completed."); 
    }

    return 0;
}
