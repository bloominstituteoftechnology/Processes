// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int main(int argc, char *argv[])
// {
//     // Your code here
//     int x = 100;
//     printf("x: %d\n", x);
//     int rc = fork();
//     // ------------------------------------------------ child process starts executing here
//     if (rc < 0) {    // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {    // child process satisfies this branch
//         x = 90;
//         printf("child printing x: %d\n", x);
//     } else {
//         x = 80;
//         printf("parent printing x: %d\n", x);
//     }

//     return 0;
// }

int main(int argc, char *argv[])
{
    // Your code here
    int test = 0;
    test = 100;
    printf("Test: %d (pid: %d)\n\n", test, (int)getpid());

    int rc = fork();
    if (rc == 0)
    {
        printf("Child: %d (pid: %d)\n", test, (int)getpid());
        test = 111;
        printf("New Child: %d (pid: %d)\n\n", test, (int)getpid());
    }
    else
    {
        printf("Parent: %d (pid: %d)\n", test, (int)getpid());
        test = 222;
        printf("New Parent: %d (pid: %d)\n\n", test, (int)getpid());
    }

    printf("New test: %d (pid: %d)\n\n", test, (int)getpid());

    return 0;
}
