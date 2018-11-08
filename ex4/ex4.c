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
    pid_t pid;

    pid = fork();

    if(pid<0){
      printf("Fork failed.\n");
      exit(1);
    }else if(pid == 0){
      //child process
      // printf("child\n");
      printf("calling ls\n");
      execl("/bin/ls", "ls", NULL);
    }else{
      //parent process
      int wc = waitpid(pid, NULL, 0);
      printf("ls finished\n");
    }

    return 0;
}
