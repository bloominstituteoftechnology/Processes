// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?


#include <stdio.h>  //installing the necessary libraries
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;    // initialize x with a value of 100
    printf("hello world (pid: %d)\n", (int) getpid()); // run hello world and printing pid or process id of the parent process.
    
    int rc = fork();    // fork function: creates a new process by duplicating the calling process. Child process is created.
    
    if (rc < 0) {   // handling error during fork()
        fprintf(stderr, "fork failed\n");   // error message
        exit(1);    // exit
    } else if (rc == 0) {   // on successful forking, this is the child process which is the duplicate of the parent process
        printf("hello, child here(pid: %d) and x is: %d\n", (int) getpid(), x); // running the exact same process as the parent; printing child's pid and value of x; child's pid or process id should not match any existing pid
        x++;    // increment x
        printf("child here again, x is now: %d\n", x);  // print child with the incremented value of x
    } else {    // on successful forking of child process, the pid of the child is returned in the parent
        printf("hello, parent here (pid: %d) of child %d and x is: %d\n", rc, (int) getpid(), x);  // printing the parent's and child's pid and the value of x 
        x--;    // decrement x
        printf("parent here again, x is now: %d\n", x); // print parent with the decremented value of x
    }

   return 0;
}