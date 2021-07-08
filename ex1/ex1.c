// // Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// // (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// // What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// int main(void)
// {
//     // Your code here
//     int x = 100;
//     printf("X in parent= %d \n", x);

//     fork();
//     printf("in forked x= %d \n", x);
    
//     return 0; 
// }
// Changing x inside of child.
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

int main(void)
{
    // Your code here
    
    
    int x = 100;
    printf("x before fork=%d \n", x);

    int pid = fork();

    if(pid==0){
        x=35;
        printf("In the child x= %d\n", x);
    }
    else {
    x=50;
    printf("In the parent x= %d \n", x);
    }
    return 0;
}
