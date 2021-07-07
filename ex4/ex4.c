// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h> // ------> see note
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();
    // error handling
    if (rc < 0) {
        fprintf(stderr, "fork FAILED!!!\n");
        exit(1);
    } else if (rc == 0) {
        // child- transform into bin/ls program
        printf("child child\n");

        // // EXAMPLE ONE: execvp()
        // char *args[] = { "ls", "-l", NULL };
        // execvp(args[0], args);

        // // EAMPLE TWO: execl()
        // // pass in arguments manually, not in an array
        // execl("/bin/ls", "ls", "-l", NULL);

        // EXAMPLE THREE: execlp()
        // you don't have to give it the Absolute path to the program = (/bin/ls)
        execlp("ls", "ls", "-l", NULL);
        
    } else {
        // parent, see ex3 for notes
        int wc = waitpid(rc, NULL, 0);
        printf("parent parent\n");
    }
     
    return 0;
}


// exec family of functions in C....https://www.geeksforgeeks.org/exec-family-of-functions-in-c/
// The exec family of functions replaces the current running
// process with a new process. It can be used to run a C program 
// by using another C program. It comes under the header file unistd.h. 
