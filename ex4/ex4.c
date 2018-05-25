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

        extern char *environ;
        char *args[] = {"ls", "-1", NULL};

        // ====== exec() variants ======= // https://en.wikipedia.org/wiki/Exec_(system_call)

        // execl("/bin/ls", "ls", "-1", (char *)NULL);
        // execlp("ls", "-1", NULL);

        // execvp("ls", args);
        // execv("/bin/ls", args);

        // execle("/bin/ls", "ls", "-1", (char *)NULL, environ);

        execve("/bin/ls", args, environ); // runs, but with warnings
    }
    else
    {
        wait(NULL);
    }
    return 0;
}
