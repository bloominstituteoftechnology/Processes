// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    // Your code here
    printf("Parent started, I don't exec.\n");
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "Failed to fork, exiting\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child started, I'm going to exec `ls`\n");

        // ===== exec() variant parameters (uncomment if needed) ===== //

        // extern char *environ;

        // char *args[] = {"ls", "-l", NULL}; // #QUESTION: What is with the `-l`???

        // ====== exec() variants ======= // https://en.wikipedia.org/wiki/Exec_(system_call)
        // https://linux.die.net/man/3/environ

        execl("/bin/ls", "ls", "-l", (char *)NULL);
        // execlp("ls", "ls", "-l", NULL);

        // execvp("ls", args);
        // execv("/bin/ls", args);

        // execle("/bin/ls", "ls", "-l", (char *)NULL, environ);

        // execve("/bin/ls", args, environ); // runs, but with warnings
    }
    else
    {
        wait(NULL);
        // This also works:
        // int wc = waitpid(rc, NULL, 0);
        printf("parent here\n");
    }
    return 0;
}
