// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

// > uses waitpid() to make sure the child process is executed first

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // this is needed for wait methods

int main(void)
{
    // Your code here
    int forkreturns = fork(); // returns the pid of the child created by fork()

    if (forkreturns == 0) {
      printf("Hello! I'm a child process. (pid: %d)\n", (int) getpid());
    } else {
      waitpid(forkreturns, NULL, 0); // waits for the child pid before starting. NULL is for like an error handling situation and 0 is for no options
      printf("Goodbye! As a parent process, I'm so proud of how you've grown up! (pid: %d) child name: (%d)\n", (int) getpid(), forkreturns);
    }

    return 0;
}
