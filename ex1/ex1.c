// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("\nParent x : %d", x);
    printf("\nParent process id : %d", (int) getpid());

    int s = fork();
   
    if(s > 0){
        printf("\nChild process created and process id : %d", s);
        x = 500;
        printf("\nIn child process x  : %d", x);
    }
    else if(s == 0){
        printf("\nIn process(which should be child process id)  : %d  x  :  %d", (int) getpid(), x);
    }
    
    return 0;
}


/*output:---
Parent x : 100
Parent process id : 15723
Child process created and process id : 15725
In child process x  : 500
Parent x : 100
Parent process id : 15723
In process(which should be child process id)  : 15725  x  :  100 */