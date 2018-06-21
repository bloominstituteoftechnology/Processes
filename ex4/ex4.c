// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// '/bin/ls' is what I know as just linux command 'ls', which lists contents of the directory.

/* exec() vs. fork()
    exec() replaces the program in the current process with a new one.
    fork() creates a brand new process with a duplicate of current program and state.

    keyword:
    For exec(): replace
    For fork(): duplicate
*/

/* exec() have quite a family:

references: 
https://stackoverflow.com/questions/4204915/please-explain-the-exec-function-and-its-family <-- check both top 2 answers
https://linux.die.net/man/3/exec

// v: arguments (i.e. programs) are passed as an array of strings to the main()
// l: arguments are passed as list of strings to the main()
// p: path to search for the new running program.
// e: envronment can be specified by caller.

execv(path, pointer to null-terminated array);
execl(path, pointer(s) to list of null-terminated strings);
execvpe()
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0)
    {
        printf("Child executing!\n");

        // one way using execl:
        execl("/bin/ls", "ls", NULL);

        /* OR  */

        // using execv:
        char *args[2];       // allocate 2 bytes of memories for array
        args[0] = "/bin/ls"; // full path to executeable
        args[1] = NULL;      // null-terminate

        execv(args[0], args);

    }
    else
    {
        wait(NULL); // wait for child; purely optional
        printf("Parent executing!\n");
    }
    return 0;
}
