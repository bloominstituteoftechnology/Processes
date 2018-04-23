// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int test_var = 113;
    int rc = fork();
    
    // Child process starts executing here
    if (rc < 0){
        // if fork fails for some reason
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ //child process statisfies this branch
        test_var = 55;
       printf("The value of test_var in the child process is %d\n", test_var); 
    } else {
        printf("Parent process value of test_var is %d\n", test_var);
        // printf("Child_var value in parent process is %d\n", child_var);
    }
    printf("Parent process value of test_var outside child ifelse is %d\n", test_var);
    return 0;
}
