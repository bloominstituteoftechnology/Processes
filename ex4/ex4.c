// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

/*
    The exec functions replaces the current running process with a new running process.
    It can be used to run a C program by using another C program.
    It comes from the header file: unistd.h

    With exec methods, the child process does not have to run the same program as the parent process.

    Members of the exec family of functions include...
        * execvp - int execvp (const char *file, char *const argv[])
            * file - points to the filename associated with the file being executed
            * argv - null terminated array of character pointers

        * execv - int execv (const char *path, char *const argv[])
            * path - points to the path of the file being executed
            * argv - null terminated array of character pointers

        * execlp and execl - int exec[lp or l] (const char *[path or file], const char *arg)
            * file/path - filename/path associated with the file being executed
            * *arg - describe a list of 1+ pointers to null terminated strings that represent
                     the argument list available to the executed program

        * execvpe and execle - same shit, different syntax
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int childProcess = fork();

    if (childProcess < 0){
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    }
    else if (childProcess == 0){
        execl("/bin/ls", "ls", "-l", (char*)NULL);

        // char *args[] = {"ls", "-l", NULL};
        // execv("/bin/ls", args);

        // execlp("ls", "ls", "-l", (char*)NULL);

        // char *args[] = {"ls", "-l", NULL};
        // execvp("ls", args);
    }
    else {
        int wait = waitpid(childProcess, NULL, 0);
    }

    return 0;
}
