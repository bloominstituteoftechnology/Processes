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

    pid_t child = fork();
    //error handling:
    if (child < 0){
      exit(1);
    }
    else if(child == 0){
      printf("the child's proceses id is %d\n", (int), getpid());
      // allocate memory for string array:
      char *argv[2];
      argv[0] = strdup("/bin/ls"); //using an array to run the bin/ls program duplicating with strdup
      argv[1] = strdup("ex4.c"); //pass this FILE
      //execs replace the current RUNNING process with a new proccess
      // again processes are the things within which programs (written sets of instructions) execute under the UNIX OS.
      execvp
    }
    else
    exec();


    return 0;
}
