// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here    
    printf("Here is the first line of text.\n");

    int rc = fork();

    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0 ) {
        printf("And here is the child call. With a PID of %d", ((int) getpid()));
        char *args[2];
        args[0] = strdup("/bin/ls");
        args[1] = NULL;
        execvp(args[0], args);
        printf("This should not print...");


    } else {
        printf("And here is the parent");
    }
    return 0;
}
