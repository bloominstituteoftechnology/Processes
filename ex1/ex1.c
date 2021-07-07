// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int x= 100;
    printf("hello, hello (pid:: %d)\n", (int) getpid());//getting the process id, pid
    int rc= fork();
    //error catch
    if  (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);

    }else if (rc == 0){
        printf("Child (pid:: %d) and x is: %d\n", (int) getpid(), x);
        printf("child, x is: %d\n", x);
        x++;
        printf("child now, x is now: %d\n", x);

    }else {
        
        printf("Parent of %d (pid: %d)and x is: %d\n", rc, (int) getpid(), x);
        x--;
        printf("here here parent, x is: %d\n", x);
    }

    return 0;
}

