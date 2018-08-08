// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int mainNum = 100;
    int rc = fork();
    if(rc < 0) {
        perror("Error forking");
        exit(-1);
    }
    if(rc == 0) {
        mainNum += 10;
        printf("Child added ten to the mainNum so now mainNum = %d \n", mainNum);
    } else {
        mainNum -= 5;
        printf("Parent subtracted 5 from the mainNum so now mainNum = %d \n", mainNum);
    }
    printf("mainNum is = %d \n", mainNum);

    return 0;
}
