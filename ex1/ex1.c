// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int main(void)
// {
//     int x = 100;
//     printf("x before fork=%d \n", x);

//     int pid = fork();

//     if(pid==0){
//         x=35;
//         printf("In the child x= %d\n", x);
//     }
//     else {
//     x=50;
//     printf("In the parent x= %d \n", x);
//     }
//     return 0;
// }

// watching videos

int main(void)
{
    int x = 100;
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, i'm a child(pid: %d) and x is: %d\n", (int) getpid(), x);
        x++;
        printf("child again, x is now: %d", x);
    } else {
        printf("hello, i'm the parent of %d (pid: %d) and x is: %d\n", rc, (int) getpid(), x);
        x--;
        printf("parent again, c is now: %d\n", x);
    }
   
    return 0;
}
