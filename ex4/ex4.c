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
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child process\n");
        // execl("/bin/ls", "ls", "-l", NULL); // doesn't take any array, you need to specify as a sting the actual path to a file
        // "/bin/ls" - location, "ls" - the name of the program, -l - is a long-form flag, NULL - terminator
        // -o - seach for all hidden files
        char *args[] = {"ls", "-l", NULL}; // transform child into ls
        // execvp("ls", args);                // same path as execl("/bin/ls", "ls", "-l", NULL)
        execv("/bin/ls", args); // absolute path
        // difference between -v and -vp, p stands for path. so with just a -v, we need to give absolute path to the file you want to execute
        printf("Not seen print\n");
    }
    else
    {
        int wait = waitpid(rc, NULL, 0);
        printf("Parent process\n");
    }

    return 0;
}
