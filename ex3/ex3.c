// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

// https://repl.it/@codejoncode/Lambda-Excercise-3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork(); 

    if(pid == 0){
      printf("hello\n");
    } else{
      wait(NULL);
      printf("goodbye\n");
    }


    return 0;
}