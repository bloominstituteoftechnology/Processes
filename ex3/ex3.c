// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    pid_t pid;

    pid = fork();

    if(pid < 0){
      printf("Fork failed.");
      exit(1);
    }else if(pid == 0){
      printf("Hello!\n");
    }else{
      int wc = waitpid(pid, NULL, 0);
      printf("Goodbye!\n");
    }
    return 0;
}
