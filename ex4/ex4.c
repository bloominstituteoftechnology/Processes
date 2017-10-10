// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  printf("hello world (pid: %d)\n", (int) getpid());
  // ----------------------------------------------- KIDS DO THE DARNDEST THINGS
  int rc = fork();
  if (rc < 0) {    // fork failed; try spoon || knife
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child process
    puts("Kid:");
    execl("/bin/ls", "ls", "-alh", (char *)0);
  } else {
    int wc = waitpid(rc, NULL, 0);
    puts("");
    printf("Parent: (pid: %d)\n\n", (int) getpid());
  }
  puts("Jigga- wOt?");
  return 0;
}
