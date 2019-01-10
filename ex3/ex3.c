// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

// - [Dig Deeper: SO's print parent process at end](https://stackoverflow.com/questions/46458684/c-how-to-print-parent-process-at-the-end-of-child)
// - [Dig Deeper: ualberta's wait & waitpid](https://webdocs.cs.ualberta.ca/~tony/C379/C379Labs/Lab3/wait.html)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here

    // starting process
    int rc = fork();
    
    // child process starts execution here
    if (rc < 0) { // fork failed; exit
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if (rc == 0) { // child process satisfies this branch
      printf("hello \n");
    }
    else {
      wait(NULL);
      // waitpid(rc, NULL, 0); // also works but has more options
      printf("goodbye \n");
    }

    return 0;
}
