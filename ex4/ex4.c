// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

//https://ece.uwaterloo.ca/~dwharder/icsrts/Tutorials/fork_exec/
//https://www.geeksforgeeks.org/exec-family-of-functions-in-c/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// int main(void)
// {
//     int rc = fork();

//     if(rc<0) {
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0){
//         printf("child process, pid = %d\n", getpid());
//     }else {
//         printf("parent process, pid = %d\n", getpid());
//     } 

//     return 0;
// }

// https://stackoverflow.com/questions/28507950/calling-ls-with-execv
int main(void)
{
    int status;
    char *args[2];

    args[0] ="/bin/ls"; //first argument = full path to file
    args[1] = NULL; //null termination

    int rc = fork();
    
    if(rc == 0)
        execv(args[0], args);
    else
        wait(&status);
    
    return 0;
}