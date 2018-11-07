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
    pid_t process;

    process = fork();

    if (process == 0) {
      printf("I'm the child!\n");
    } else {
      printf("Parent is about to wait!\n");
      wait(NULL);
      printf("I'm the parent!\n");
    }

	return 0;
}
