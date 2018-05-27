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
    printf("ex3 executing...\n");

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child running...\nHello\n");
    }
    else
    {
        // `waitpid` call added here
        // #QUESTION: Why does it throw an 'unused variable' error?
        // // Fixed by removing `int wc =`
        waitpid(rc, NULL, 0);
        printf("Parent running...\nGoodbye\n");
    }
    return 0;
}
