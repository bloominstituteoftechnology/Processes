// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

// On wait, waitpid, zombie process, orphan process and more! => https://notLike es.shichao.io/apue/ch8/#zombie-process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // `waitpid` needs to be included separately

// `gcc -Wall -Wextra -o ex3 ex3.c`
// `./ex3`

// int argc, char* argv[]
int main()
{
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child (pid: %d)running...\nHello\n", getpid());
    }
    else
    {
        // `waitpid` call added here
        // #QUESTION: Why does it throw an 'unused variable' error?
        // // Fixed by removing `int wc =`
        int wc = waitpid(rc, NULL, 0);
        printf("Child's exit status: %d\n", wc); // waitpid() returns the pid of whatever it waited on
        printf("Parent (pid: %d) of %d running...\nGoodbye\n", getpid(), rc);
    }
    return 0;
}
