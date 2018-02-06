// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?
//
//https://stackoverflow.com/questions/11733481/can-anyone-explain-a-simple-description-regarding-file-descriptor-after-fork
//In "Advanced Programming in the Unix Environment", 2nd edition,
//By W. Richard Stevens.
//8.10 exec Functions pg 249
/* ###################################################################
We mentioned in Section 8.3 that one use of the fork function is to create a new process
(the child) that then causes another program to be executed by calling one of the exec
functions. When a process calls one of the exec functions, that process is completely
replaced by the new program, and the new program starts executing at its main
function. The process ID does not change across an exec, because a new process is not
created; exec merely replaces the current process — its text, data, heap, and stack
segments — with a brand-new program from disk.
There are seven different exec functions, but we’ll often simply refer to ‘‘the exec
function,’’ which means that we could use any of the seven functions. These seven
functions round out the UNIX System process control primitives. With fork, we can
create new processes; and with the exec functions, we can initiate new programs. The
exit function and the wait functions handle termination and waiting for termination.
These are the only process control primitives we need. We’ll use these primitives in
later sections to build additional functions, such as popen and system.

  ###################################################################
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void err_sys(const char *x)
{
    perror(x);
    exit(1);
}

// int main(int argc, char *argv[])
// {
//     // Your code here

//     return 0;
// }

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(int argc, char *argv[])
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    { /* specify pathname, specify environment */
        if (execle("/home/sar/bin/echoall", "echoall", "myarg1",
                   "MY ARG2", (char *)0, env_init) < 0)
            err_sys("execle error");
    }
    if (waitpid(pid, NULL, 0) < 0)
        err_sys("wait error");
    if ((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    { /* specify filename, inherit environment */
        if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
            err_sys("execlp error");
    }
    exit(0);
}