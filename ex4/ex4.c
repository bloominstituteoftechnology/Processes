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
    printf("Before fork(), (pid: %d).\n", (int) getpid());
    int f = fork();
    printf("After fork(), (pid: %d).\n", (int) getpid());

    if (f > 0)
    {
        int wc = waitpid(f, NULL, 0); 
        //wait() is needed if not those calling file fail, 
        //and those calling path give a different response
        printf("I am the parent (pid: %d)! of child %d.\n", (int) getpid(), f);

    }
    else if (f == 0)
    {
        printf("I am the child, (pid: %d).\n", (int) getpid());
        char *args[2];

        args[0] = strdup("wc");
        args[1] = strdup("/bin/ls");
        args[2] = NULL;

        execvp(args[0], args); //printed: 465   3370 133792 /bin/ls
        // execvpe(args[0], args); //printed: 465      s3370 133792 /bin/ls
        // execl(args[1], args, "-1", NULL); //printed: ex4 ex4.c in their own lines
        // execlp(args[1], args, "-1", NULL); //printed: ex4 ex4.c in their own lines

        printf("If this shows up exec() member failed!\n");
    }
    else
    {
        fprintf(stderr, "Fork Failed!\n");
        exit(1);
    }
    return 0;
}

// Functions in the exec() family have different behaviours:
    // l : arguments are passed as a list of strings to the main()
    // v : arguments are passed as an array of strings to the main()
    // p : path/s to search for the new running program
    // e : the environment can be specified by the caller

// You can mix them, therefore you have:
    // int execl(const char *path, const char *arg, ...);
    // int execlp(const char *file, const char *arg, ...);
    // int execle(const char *path, const char *arg, ..., char * const envp[]);
    // int execv(const char *path, char *const argv[]);
    // int execvp(const char *file, char *const argv[]);
    // int execvpe(const char *file, char *const argv[], char *const envp[]);
// For all of them the initial argument is the name of a file that is to be executed.
// https://stackoverflow.com/questions/4204915/please-explain-the-exec-function-and-its-family
