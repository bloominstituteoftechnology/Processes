// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    // Your code here  
    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "The fork was a failure, now exiting\n");
        exit(1);
    }  else if(rc == 0) {
        char *args[2];
        args[0] = strdup("/bin/ls");
        args[1] = NULL;

        execvp(args[0], args);
    } else {
        sleep(1);
    }

    return 0;
}
