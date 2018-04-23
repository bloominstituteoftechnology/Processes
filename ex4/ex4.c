// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

//int main(int argc, char* argv[])
int main()
{
    // Your code here
    printf("Parent started, I don't exec.\n");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Failed to fork, exiting\n");
        exit(1);
    } else if (rc == 0) {
        extern char **environ;
        char *args[] = {"ls", "-1", NULL};

        printf("Child started, I'm going to exec `ls`\n");
        // execl("/bin/ls", "ls", "-1", (char *)NULL);
        // execle("/bin/ls", "ls", "-1", (char *)NULL, environ);
        // execlp("ls", "ls", "-1", environ);
        // execv("/bin/ls", args);
        // execve("/bin/ls", args, environ);
        // execvp("ls", args);
        execvpe("ls", args, environ);
    } else {
        wait(NULL);
    }
    return 0;
}

// https://en.wikipedia.org/wiki/Exec_(system_call)
// e – An array of pointers to environment variables is explicitly passed to the new process image.
// l – Command-line arguments are passed individually (a list) to the function.
// p – Uses the PATH environment variable to find the file named in the file argument to be executed.
// v – Command-line arguments are passed to the function as an array (vector) of pointers.