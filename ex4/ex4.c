// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  // Your code here
  int child = fork();
  if (child < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (child == 0) {
    // execl("/bin/ls", "/bin/ls", (char *) 0);
    execle("/bin/ls", "/bin/ls", NULL, NULL);
    printf("child: %s", "This Shouldn't Run\n");
  } else {
    int wc = waitpid(child, NULL, 0);
    printf("parent: %s", "This May Run\n");
  }
  return 0;
}
