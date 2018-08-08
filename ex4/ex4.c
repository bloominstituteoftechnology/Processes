// Write a program that calls `fork()` and then 
//calls some form of `exec()`
// to run the program `/bin/ls`. 
//Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. 
//Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    printf("Hello World! (pid: %d)", (int) getpid());
    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){
        printf("\nYo...there's a kid here...\n");
        char *myargs[3];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = strdup("ex4");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("\nlalalalala this should not be seen if all goes according to plan....\n");
    }
    else{
        waitpid(rc, NULL, 0);
        printf("\nhello, parent here (pid: %d) of child (pid: %d)\n", (int) getpid(), rc);
    }

    return 0;
}

/*
l - arguments are passed as a list of one or more pointers to null terminated strings that 
represent the argument list available to the exec program. First arg should point to file assoc
with file being executed. 

v - arguments are passed as an array of pointers to null terminated strings that represent
the argument list available to the new program. 

p - path/s to search for in the new running program

e - the environment can be specified by the caller

You can mix and match depending on your needs.

*/