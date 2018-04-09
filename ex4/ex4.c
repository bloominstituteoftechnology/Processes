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
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char *myargs = {"/bin/ls"};
        printf("Chid here. I am about to run my own program.\n");
        execv("/bin/ls", &myargs);
        // execl("/bin/ls", "bin", NULL);
    } else {
        int wc = waitpid(rc, NULL, 0);
        printf("Parent here. I'm coming after child program.\n");
    }

    return 0;
}
