// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char* argv[])
{
    // Your code here
    int X = 100;
    int *x = &X;
    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child
        // char *myargst[] = {   // allocate an array
        // "ls",    // pass the name of the program we want to run as the first array element 
        // "-la",    // argument: the ls switches
        // "-hulo",
        // "--color=yes",
        // NULL};  
        // //printf("myargs: %s %s %s %s\n", myargs[0],myargs[1],myargs[2],myargs[3]);
        // execvp(myargst[0], myargst);  
        // char *myargs[] = {   // allocate an array 
        // // // `strdup` duplicates the given input string 
        // "wc",    // pass the name of the program we want to run as the first array element 
        // "./ex4.c",    // argument: the file to count
        // NULL};    // marks the end of the array
        // execvp(myargs[0], myargs);    // runs the word count program, passing in the `myargs` array to the word count program as arguments
        char * slscolor =  getenv("LS_COLORS");
        char buffer[0x10000];
        sprintf(buffer, "LS_SWITCHES4=%s", slscolor);
        const char const * LS_SWITCHES[] = { "LS_SWITCHES1=-la", "LS_SWITCHES2=--color=yes", "LS_SWITCHES3=-hula", buffer,  NULL };
        char *myargse[] = {   // allocate an array 
        // `strdup` duplicates the given input string 
        "./testEnv",    // pass the name of the program we want to run as the first array element 
        NULL};    // marks the end of the array
        execvpe(myargse[0], myargse, (char * const*) LS_SWITCHES);    // runs the testEnv program, passing in the ls switch in the Environment
        
    }
    else
    { // parent

        int wc = waitpid(rc, NULL, 0);
        puts("exiting parent");
    }
    exit(0);
}

