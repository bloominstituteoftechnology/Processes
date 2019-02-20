// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// 1. Why do you think there are so many variants of the same basic call?
// Just many ways to run a program with different arguments, paths, and environmental variables.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here

    // parent asking OS to start new process, 1 process
    int rc = fork();

    // parent and child processes return from fork(), 2 processes
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child
        printf("From child, PID: %d, PPID: %d \n\n", getpid(), getppid());
        wait(NULL); // wait for child process to join with the parent

        // execl
        int proc1 = execl("/bin/ls", "ls", "-ls", NULL); // returns list direction with long form and file size
        printf("proc1 %d \n", proc1);

        // execvp
        // char *myargs[4];
        // myargs[0] = "/bin/echo"; // "echo" also works since execv p flag also initiates search
        // myargs[1] = "echo";
        // myargs[2] = "web development";
        // myargs[3] = NULL;
        // int proc2 = execvp(myargs[0], myargs); // 1st argument always is program to run, echos array arguments
        // printf("proc2 %d \n", proc2);
    }
    else
    { // parent
        printf("From parent, PID: %d, PPDI: %d \n", getpid(), rc);
    }

    return 0;
}
