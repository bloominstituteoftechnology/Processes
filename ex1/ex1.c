// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?




// init is PID 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>             // required for fork()
// #include <sys/wait.h>           // required for wait()
                                // when sys.wait wasn't added it could run in different orders
int main(void) {

    int x  = 100;
    pid_t pid;        // _t means type delcaration pid under the hood it is an int.
    pid = fork(); // doesn't take paramters
    if (pid < 0) {
        printf("Can't fork; error occured\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        x = 7;
        printf("From child (pid %d): x is %d\n", (int) getpid(), x);      // x = 7
    } else {
        printf("From parent (pid %d): x is %d\n", (int) getpid(), x);      // x = 100
        x = 10;
        // wait(NULL); // if this is commentted result will be different.
        int wc = waitpid(pid, NULL, 0);
        printf("From parent (pid %d) of child (pid %d): x is %d\n", (int) getpid(), pid, x);      // x = 10
    }
/*
Order run:
100
10
7

But without wait it could be:
7
100
10
*/

  return 0;
}
