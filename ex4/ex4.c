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
    pid_t pid = fork();

    char *bin_ref = {"./bin/ls", NULL}; /* might try running another file from this project at some point too */
    exec(bin_ref[0], bin_ref);
    // execl(bin_ref[0], bin_ref);
    // execle(bin_ref[0], bin_ref);
    // execvp(bin_ref[0], bin_ref);
    return 0;
}

/* The different versions seem to mainly reference parameters.
For example, -l includes individual parameters in the call, whereas -v is useful when
variables are not known in advance because it allows you to pass in a char* array
rather than a specific number of parameters. There is some additional functionality 
with things like -e and -p and I'd be lying if I said I understand this fully yet, so
I'm going to keep looking into these differences. */
