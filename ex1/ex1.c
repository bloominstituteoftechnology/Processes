// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = 3;
    x += 39;
    printf("x is %d \n", x);
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("child: x is now %d\n",x);
        x++;
        printf("parent again: x is now %d\n",x);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("parent: x is now %d\n",x);
        x--;
        printf("parent again: x is now %d\n",x);
    }
    return 0;
}
