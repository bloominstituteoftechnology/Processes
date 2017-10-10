// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>    // `waitpid` needs to be included separately

int main(int argc, char *argv[]) {
  printf("What to say to the world? (pid: %d)\n", (int) getpid());
  // ------------------------------------------------ child process starts executing here
  int rc = fork();
  if (rc < 0) {    // fork failed; try spoon || knife
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {    // child process satisfies this branch
    printf("HELLO, child here (pid: %d)\n", (int) getpid());
  } else {
    int wait = waitpid(rc, NULL, 0); // Kids FIRST!
    printf("GOODBYE, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
  }
  puts("wOt?");

  return 0;
}
