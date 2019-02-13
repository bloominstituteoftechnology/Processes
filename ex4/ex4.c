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
    int status;
    // 2 strings, one is /bin/ls and the other is to finish with a NULL
    char *args[2];

    args[0] = "/bin/ls";
    args[1] = NULL;
    int y = fork(); 

    if (y == 0) {
    execv(args[0], args);

  } else {
    
    wait(&status);
  }

    return 0;
}
