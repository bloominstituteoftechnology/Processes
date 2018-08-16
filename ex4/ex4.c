// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h> // system calls (fork, exec)
#include <stdlib.h>
#include <sys/wait.h> // needed for use with waitpid()

int main(void)
{
    // Your code here
    int rc = fork(); // create a child process

    if (rc < 0)
    { // if fork failed print out a standard error message and exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) // represents child process
    {
        printf("Child process here\n");

        //exec system calls with v in the name take an array parameter to specify the argv[] array of the new program. Calls with l means the function takes a list of arguments and is mutually exclusive with the letter v. Calls with p means that the function takes a file name argument and use the PATH environ variable to find the executable file.

        // execl("/bin/ls", "ls", "-l" (char *) NULL);

        // char *args[] = {"ls", "-l", NULL};
        // execv("/bin/ls", args);

        //execlp("ls", "ls", "-l", (char *) NULL);

        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args); // takes two parameters, a filename and uses the PATH environment variable to find the executable file, and the array of pointers terminated by a NULL pointer
    }
    else // represents parent process
    {
        int wc = waitpid(rc, NULL, 0); // ensures that the parent process only runs after the child process has finished executing
    }

    return 0; // needs to return an integer
}
