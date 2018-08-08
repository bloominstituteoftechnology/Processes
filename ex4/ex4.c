// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int fork_process = fork();

    if (fork_process < 0)
    {
        fprintf(stderr, "Something went wronk forking %d process\n", (int)getpid());
    }
    else if (fork_process == 0)
    {
        printf("=== %d CHILD_START ===\n", (int)getpid());

        printf("\nexecv\n");
        char *argmts[] = {"/bin/ls", "-l", NULL};
        execv(argmts[0], argmts);

        printf("=== CHILD_END ===\n");
    }
    else
    {
        printf("=== %d PARENT_START ===\n", (int)getpid());

        waitpid(fork_process, NULL, 0);

        printf("\nexecl\n");
        execl("/bin/ls", "ls", "-l", "-a", (char *)0);

        printf("=== PARENT_END ===\n");
    }
    printf("END");

    return 0;
}

/*
*********  OUTPUT  *********
TERMINAL
=== 8488 PARENT_START ===
=== 8489 CHILD_START ===

execv
total 32
-rwxr-xr-x  1 jesuarva  staff  8888  8 Aug 23:46 ex4
-rw-r--r--  1 jesuarva  staff  1087  8 Aug 23:46 ex4.c

execl
total 32
drwxr-xr-x   4 jesuarva  staff   136  8 Aug 23:46 .
drwxr-xr-x  14 jesuarva  staff   476  8 Aug 21:10 ..
-rwxr-xr-x   1 jesuarva  staff  8888  8 Aug 23:46 ex4
-rw-r--r--   1 jesuarva  staff  1087  8 Aug 23:46 ex4.c

I think each of the several different variants of the exec()
fullfills a different need a developer may have,
these are brief descriptions of the 'different' options the family have:

FLAGS:
l : arguments are passed as a list of strings to the main()
v : arguments are passed as an array of strings to the main()
p : path/s to search for the new running program
e : the environment can be specified by the caller
*/