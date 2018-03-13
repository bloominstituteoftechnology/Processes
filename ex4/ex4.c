// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?
// Answer:
// The differences are combinations of:
// L vs V: whether you want to pass the parameters to the exec'ed program as
// L: individual parameters in the call (variable argument list): execl(), execle(), execlp(), and execlpe()
// V: as an array of char* execv(), execve(), execvp(), and execvpe()
// The array format is useful when the number of parameters that are to be sent to the exec'ed process are variable --
// as in not known in advance, so you can't put in a fixed number of parameters in a function call.
// E: The versions with an 'e' at the end let you additionally pass an array of char* that are a set of strings 
// added to the spawned processes environment before the exec'ed program launches. 
// Yet another way of passing parameters, really.
// P: The versions with 'p' in there use the environment path variable to search for the executable file named to execute. 
// The versions without the 'p' require an absolute or relative file path to be prepended to 
// the filename of the executable if it is not in the current working directory.
// (this was before function polymorphism which was introduced in C+=, Java, JS etc. now also available in C)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here    
    printf("Parent process here\n");
    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0) {
        printf("Child process here\n");
        
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
    } else {
        wait(NULL);
    }

    return 0;
}
