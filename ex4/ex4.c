// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    printf("Before forking pid: %d\n", (int) getpid());

    pid_t pid = fork();

    if (pid < 0) //fork failed
    {
        exit(1);
    } 
    else if (pid == 0) //child process
    {
        printf("AFTER forking CHILD pid: %d\n", (int) getpid());

        char *myargs[2];    // allocate an array of chars to hold 2 bytes
        
        // `strdup` duplicates the given input string 
        myargs[0] = strdup("/bin/ls");      // pass the name of the program we want to run as the first array element 
        //myargs[1] = strdup("ex4.c");    // argument: the file to count
        myargs[1] = NULL;              // marks the end of the array
        
        
        execvp(myargs[0], myargs);     // runs the word count program, passing in the `myargs` array to the word count program as arguments
        execvp(myargs[0], myargs);     // runs the word count program, passing in the `myargs` array to the word count program as arguments
        
        printf("this should not be seen");

    }
    else {
        //wait for child to complete
        waitpid(pid, NULL, 0); 
        printf("1st exec: AFTER forking PARENT pid: %d\n", (int) getpid());
        
        char *myargs[3];    // allocate an array of chars to hold 3 bytes
        // `strdup` duplicates the given input string 
        myargs[0] = strdup("wc");      // pass the name of the program we want to run as the first array element 
        myargs[1] = strdup("ex4.c");    // argument: the file to count
        myargs[2] = NULL;              // marks the end of the array
        execvp(myargs[0], myargs);     // runs the word count program, passing in the `myargs` array to the word count program as arguments
        printf("this should not be seen");


        printf("\n2nd exec: PARENT pid: %d\n", (int) getpid());
        char *secondExec = "wc ex4.c";   // allocate an array of chars to hold 3 bytes
        // `strdup` duplicates the given input string 
        execl(secondExec);     // runs the word count program, passing in the `myargs` array to the word count program as arguments
        printf("this should not be seen");
    }
    return 0;
}
