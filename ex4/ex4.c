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
    pid_t pid;   
    pid = fork();  
    char *argv[3] = {"/bin/ls", ".", NULL}; // execvp( "find", argv );

    if (pid == 0) {
        execvp( "find", argv );
        //  ./ex4
        //  ./ex4.c

    } else {
        printf("Parent says hello\n");
    }
    return 0;
}

/*
https://ece.uwaterloo.ca/~dwharder/icsrts/Tutorials/fork_exec/
"The exec Family of Functions
There is a family of exec() functions, all of which have slightly different characteristics:

       int execl ( const char *path, const char *arg, ... );
       int execlp( const char *file, const char *arg, ... );
       int execle( const char *path, const char *arg, ..., char *const envp[] );
       int execv ( const char *path, char *const argv[] );
       int execvp( const char *file, char *const argv[] );
       int execve( const char *file, char *const argv[], char *const envp[] );
Each system call is the word exec followed by either l or v and then possibly followed by either e or p.

The first three have are of the form execl and accept a variable number of arguments. In order to use this feature, you must load the <stdarg.h> header file. Please see the example stdarg.c.

The latter three are of the form execv in which case the arguments are passed using an array of pointers to strings where the last entry is NULL. For example, you might have:
        char *argv[] = {"Hello ", "world!", NULL};

If the name ends in either l or v, the program name must be given in full.

If the name is appended by a p, it will search for the file using the current environment variable PATH, which usually includes /bin/, /usr/bin/, etc.

Finally, if the name is appended by a e, one can include an array of strings indicating environment variables, each of the form "ENVVAR=value" and the array being null terminated. For example,
       char *envp[] = {"USER=dwharder", "HOME=/home/dwharder", NULL};
"

*/
