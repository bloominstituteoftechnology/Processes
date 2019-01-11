// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{pid_t pid;

 pid = fork();
  
  if (pid == 0){
    printf("I am the child, about to start process using execlp.\n");
    execlp("ls","ls", NULL);
    printf("The call to execlp() was not successful.\n");
   }else{
    wait(0);              
    printf("I am the parent.  The child just ended.  I will now exit.\n");
   }
    return 0;
}