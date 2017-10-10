// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
  FILE *file = fopen("./text.txt", "w");
  // ---------------------------------------------- KIDS SAY THE DARNDEST THINGS
  int rc = fork();
  if (rc < 0) { // fork failed; try spoon || knife
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child process
    char strChild[] = "Child Process\n";
    fwrite(strChild, 1, sizeof(strChild), file);
  } else {
    char strParent[] = "Parent process\n";
    fwrite(strParent, 1, sizeof(strParent), file);
  }
  return 0;
}
