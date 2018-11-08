// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call? different types of pointers to make the call with
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int f = fork();

    if (f < 0) 
    {
        fprintf(stderr, "fork failed\n");
    
    } else if (f == 0) 
    {
        printf("I'm the kid (pid: %d)\n", (int) getpid());
        char *myArgs[2];

        myArgs[0] = "/bin/ls";
        myArgs[1] = NULL;

        // execv(myArgs[0], myArgs);
        execvp(myArgs[0], myArgs);
        fprintf(stderr, "execvp failed\n");
        // you can write an error fprintf under here, because if execvp is successful
        // no code under execvp should run
        // but yeah it's workin shouldn't it show more what my 1: bash terminal shows though or is there a way I coudl get that? cause that means what it just ran the file we were already in? or idk?
    } else 
    {
        int holdup = waitpid(f, NULL, 0);
        printf("Parent here (pid: %d) of child %d\n", (int) getpid(), f);
    }
  
    return 0;
}
