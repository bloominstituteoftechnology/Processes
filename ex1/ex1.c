// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 0;
    printf("Intial = %d \n", x);
    x = 100;
    printf("Parent set = %d \n", x);

    int child = fork();

    if (child == 0){
        printf("Pre Child set = %d \n", x);
        x = 50;
        printf("Post Child set = %d \n", x);
    }
    else{
        x = 75;
        printf("Parent post fork set = %d \n",x);
    }

    printf("Final X check = %d \n",x);

    return 0;
}
