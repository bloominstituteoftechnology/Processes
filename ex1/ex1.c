// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
// init is 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>             // required for fork()
#include <sys.wait.h>           // required for wait()
                                // when sys.wait wasn't added it could run in different orders
int main(void) {

    int x  = 100;
    pid_t pid;        // _t means type delcaration pid under the hood it is an int.
    pid = fork(); // doesn't take paramters

    if (pid == 0) {
        x = 7;
        printf("%d\n", x);
    } else {
        printf("%d\n", x);
        wait(NULL); // if this is commentted result will be different.
        printf("%d\n", x);
    }


  return 0;
}
