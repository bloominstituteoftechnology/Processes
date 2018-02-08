// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc <0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("I am from the child\n");
        execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("I am from the parent\n");
        char *args[] = {"/bin/ls", "-r", "-t", "-l", (char *) 0 };
        execv("/bin/ls", args);
    }

    return 0;
}

// all execs allow the child process to run a different program from the parent process
// l type execs accept a variable number of arguments, and requires stdarg.h
// v type use an array of pointers to strings where the last entry is NULL
// if there are no additional letters, both l and v types must have the program name provided in full
// p allows the program to search for the file in a given path
// e allows you to stipulate environment variables, must be null terminated

// execvp & execv both use the same syntax - int execvp (const char *file, char * const argv[]); arguments are passed as null terminated array of pointers, first element of argv[0] is the command name
// execlp & execl - int execlp(const char *file, const char *arg, .../* (char *) NULL */) - they allow you to pass in multiple args, and uses the environment variable path
//execvpe - int execvpe(const char *file, char *const argv[], char *const envp[]);
// execle - int execle(const char *path, const char *arg, .../*, (char *) NULL, char * const envp[] */); these two allow you to stipulate environments that the process should run in