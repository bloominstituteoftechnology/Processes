// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>  

int main(void)
{
    // Your code here    
    int rc = fork();
    if(rc < 0) {
        perror("Error forking....\n");
        exit(-1);
    } else if(rc == 0) {
        printf("Child executing\n");
        execl("/bin/ls", "", "ls", NULL);
    } else {
        wait(NULL); // wait for child
        printf("Parent executing\n");
    }


    return 0;
}

// int main(int argc, char *argv[])
// {
//     printf("hello world\n");
//     int rc = fork();
//     // ------------------------------------------------ child process starts executing here
//     if (rc < 0) {    // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {    // child process satisfies this branch
//         printf("hello, child here (pid: %d) \n", (int) getpid());
//         char *myargs[3];    // allocate an array of chars to hold 3 bytes
//         // `strdup` duplicates the given input string 
//         myargs[0] = strdup("wc");      // pass the name of the program we want to run as the first array element 
//         myargs[1] = strdup("p3.c");    // argument: the file to count
//         myargs[2] = NULL;              // marks the end of the array
//         execvp(myargs[0], myargs);     // runs the word count program, passing in the `myargs` array to the word count program as arguments
//         printf("this should not be seen");
//     } else {
//         int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
//         printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
//     }

//     return 0;
// }