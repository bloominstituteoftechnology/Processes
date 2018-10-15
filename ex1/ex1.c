// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// solution
// printf() - prints to standard output (main output of your terminal)
// fprintf() - give you a choice where you want to direct output
// fprintf(stdout, "hi") same as printf("hi")
// fisrt arg to pass to fprintf is the handle of where to direct the output
// stderr is a file pointer

int main(void)
{
    int x = 100;
    printf("hello (pid: %d)\n", (int)getpid());

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) // child process
    {
        printf("hello child (pid: %d) and x is: %d\n", (int)getpid(), x);
        x++;
        printf("child again x is now: %d\n", x);
    }
    else // parent process
    {
        // wait(NULL);
        printf("hello, parent of child %d is (pid: %d) and x is: %d\n", rc, getpid(), x);
        x--;
        printf("parent again, x is now: %d\n", x);
    }

    return 0;
}

// int main(void)
// {
//     int x = 100;
//     printf(" Value of x is %d\n ", x);

//     int newP = fork();
//     printf("parent is calling for a child value %d\n", newP);
//     // Your code here
//     if (newP == 0)
//     {
//         printf(" if pid == 0 , value of x is %d\n", x);
//         printf(" if pid == 0 , newP is %d\n", newP);
//         x = 94;
//         printf("after value is = 94, x is %d\n", x);
//         printf("after value is = 94, newP is %d\n", newP);
//     }
//     else
//     {
//         printf(" else x is %d\n", x);
//         printf(" else newP is %d\n", newP);
//         x = 43;
//         printf(" after value is = 43, x is %d\n", x);
//         printf(" after value is = 43, newP is %d\n", newP);
//     }

//     return 0;
// }