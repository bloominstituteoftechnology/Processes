// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?
// The differences are combinations of:
// L vs V: whether you want to pass the parameters to the exec'ed program as
// L: individual parameters in the call (variable argument list): execl(), execle(), execlp(), and execlpe()
// V: as an array of char* execv(), execve(), execvp(), and execvpe()
// The array format is useful when the number of parameters that are to be sent to the exec'ed process are variable --
// as in not known in advance, so you can't put in a fixed number of parameters in a function call.
// E: The versions with an 'e' at the end let you additionally pass an array of char* that are a set of strings 
// added to the spawned processes environment before the exec'ed program launches. 
// Yet another way of passing parameters, really.
// P: The versions with 'p' in there use the environment path variable to search for the executable file named to execute. 
// The versions without the 'p' require an absolute or relative file path to be prepended to 
// the filename of the executable if it is not in the current working directory.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        execl("/bin/ls", 0);
        perror("execl() failure!\n\n");
    } else {
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
    }
    return 0;
}
