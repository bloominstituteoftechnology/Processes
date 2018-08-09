// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int fork_process = fork();
    int v = 0;

    if (fork_process < 0)
    {
        fprintf(stderr, "Something went wronk forking %d process\n", (int)getpid());
    }
    else if (fork_process == 0)
    {
        printf("=== CHILD_1 === variable 'v' = %d\n", v);
        v++;
        printf("=== CHILD_2 === variable 'v' = %d\n", v);
    }
    else
    {
        printf("=== PARENT_1 === variable 'v' = %d\n", v);
        v--;
        printf("=== PARENT_2 === variable 'v' = %d\n", v);
    }

    return 0;
}

// *********  OUTPUT  *********
/*
=== PARENT_1 === variable 'v' = 0
=== PARENT_2 === variable 'v' = -1
=== CHILD_1 === variable 'v' = 0
=== CHILD_2 === variable 'v' = 1

I could infer that 
1. Child process inherit the current STATE of the Parent process.
2. Due to the naturallity of processes (they are in independent 'scopes/execution context')
variable manipulation do not extends to other processes.
*/