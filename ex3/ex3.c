// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Your code here
    int child = fork();

    if (child < 0) {
      fprintf(stderr, "fork failed...\n");
      exit(1);
    } else if (child == 0) {
      printf("Hello!\n");
    } else {
      int wc = waitpid(child, NULL, 0);
      printf("Goodbye!\n");
    }

    return 0;
}
