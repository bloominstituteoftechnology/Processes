// Write a program that calls `fork()`. Before calling `fork()`, 
//have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the 
//variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 13;
        printf("Child: %d\n",x);
    } else {
        int wc = waitpid(rc, NULL, 0);
        x = 19;
        printf("Parent: %d\n", x);
    }

    return 0;
}

//solution lecture code

int main(void)
{
    inx = 100
    printf("hello (pod %d\n", (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");

    } else if(rc == 0) {
        printf("hello child (pid: %d) and x is: %d\n", (int) getpid(), x);
        x++;
        printf("child again x is now: %d\n", x);
    } else {
        printf("hello parent (pid: %d) and x is: %d\n", rc, getpid(), x);
        x--;
        printf("child again x is now: %d\n", x);
    }

    return 0;
}