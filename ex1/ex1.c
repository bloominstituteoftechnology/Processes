// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int *x = malloc(sizeof(int));
    pid_t pid = fork();
    (*x)++;
    if (pid == 0)
    {
        printf("%d Child proccess 1 %d\n", *x, pid);
        (*x)++;
        printf("%d Child proccess 2 %d\n", *x, pid);

        execlp("ls", "ls", NULL);
        perror("exec");

        (*x)++;
        printf("%d Child proccess 3 %d\n", *x, pid);
        // exit(1);
    }
    else
    {
        printf("%d Parent processes 1 %d\n", *x, pid);
        (*x)++;
        printf("%d Parent processes 2 %d\n", *x, pid);
        waitpid(pid, 1, 1);
        (*x)++;
        printf("%d Parent processes 3 %d\n", *x, pid);
    }
    return 0;
}
