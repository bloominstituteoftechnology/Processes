// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// The child process and the parent process has their own x variable after the fork. It does not change if the parent changes the x value. Only the parent's processe's x will change.
// 
// parent process: 21535
// Process run: 100
// I'm a parent process: 21535
// I'm a process: 21535, x is 100
// Process run: 100
// I'm a child process: 21536
// I'm a process: 21536, x is 50
int main(void)
{
    printf("parent process: %d\n", getpid());
    int x = 100;
    int pid = fork();
    printf("X variable: %d - for process: %d\n", x, getpid());
    if(pid == 0) {
        printf("I'm a child process: %d\n", getpid());
        x = 50;
    }
    else {
        printf("I'm a parent process: %d\n", getpid());
    }
    printf("I'm a process: %d, x is %d\n", getpid(), x);
    return 0;
}

// // p1.c
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main(int argc, char *argv[])
// {
//     printf("hello world (pid: %d)\n", (int) getpid());
//     int x = 100;
//     int rc = fork();
//     // ------------------------------------------------ child process starts executing here
//     printf("x is: %d\n", x);
//     if (rc < 0) {    // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {    // child process satisfies this branch
//         printf("hello, child here (pid: %d) \n", (int) getpid());
//     } else {
//         printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
//         x = 50;
//     }

//     return 0;
// }