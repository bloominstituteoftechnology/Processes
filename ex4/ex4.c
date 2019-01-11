// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork did not succeed\n");
        exit(1);
    } else if (rc == 0) {
        printf("CHILD (pid: %d) \n", (int) getpid());
        char *myargs[2];    // allocate an array of chars to hold 3 bytes
        // `strdup` duplicates the given input string
        myargs[0] = "/bin/ls";      // pass the name of the program we want to run as the first array element 
        myargs[1] = NULL;              // end of the array
        //execvp(myargs[0], myargs);
        execlp("/bin/ls", "ls", (char *) 0);

        printf("this will not be seen, I still don't know why\n");
    } else {
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
        printf("PARENT (pid: %d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}