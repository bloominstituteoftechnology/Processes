// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// To create a new process, duplicate a process currently running using fork()
#include <stdio.h>  // to use printf(), perror()?
#include <stdlib.h> // to use getpid()?
#include <unistd.h> // to use fork()

int main(int argc, char *argv[])
{
    // initial process
    printf("I am (initial): %d\n", (int)getpid()); // the (int) is type casting the getpid return value, which is pid_t

    int x = 100;
    printf("The value of 'x' is %d\n", x);

    // duplicating process
    // fork returns type pid_t
    // returns once for each process
    // returns child process (duplicated process)
    // returns duplicate child pid to the parent
    // returns 0 if child process is successful
    // return -1 if not successful, errno -g variable is set
    pid_t pid = fork();
    printf("Fork returned: %d\n", (int)pid);

    // ===== child process executes from here =====
    if (pid < 0)
    {
        // error printing that can be overwritten
        perror("Fork failed\n");
    }
    if (pid == 0)
    {
        // !! notice printing getpid() value instead of pid variable value
        printf("I am the child with pid %d\n", (int)getpid());

        // print value of x before child changes the value
        printf("The value of 'x' before is %d\n", x);
        x = 300;
        // print value of x after child changes the value
        printf("The value of 'x' after is %d\n", x);

        // terminates with no errors
        exit(0);
    }

    // with exit(0) in child conditional statement
    // when execution gets here, it must be the parent
    printf("I am the parent\n");

    // print value of x before parent changes the value
    printf("The value of 'x' before is %d\n", x);
    x = 200;
    // print value of x after parent changes the value
    printf("The value of 'x' after is %d\n", x);

    return 0;
}

// output

// I am (initial): 1637
// The value of 'x' is 100
// fork returned: 1638
// I am the parent
// The value of 'x' before is 100
// The value of 'x' after is 200
// fork returned: 0
// I am the child with pid 1638
// The value of 'x' before is 100
// The value of 'x' after is 300

// !! The value of 'x' before BOTH the parent and child change it is 100.
// !! Observing 'x' before the child changes it is NOT 200, which the parent changes 'x' to before the child process executes the same command
// !! Meaning the child receives the parent's lines of execution only before the fork