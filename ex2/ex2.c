// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?
//
// The child does not have access to the file.
// When writing to the files concurrently, the child takes precedence over the parent.
// I assume this is because the child process is called last, so whatever is being written from
// the child to the file will overwrite what was written from the parent to the file.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    fp = fopen("text.txt", "r");

    pid_t pid = fork();

    // Check if file exists, otherwise, output error
  if (fp == NULL) {
		printf("Failed To Open File\n");
		return 0;
	}

  if (pid == 0) {
    printf("Child\n");
    int c;

    while(1) {
      c = fgetc(fp);
      if (feof(fp)) {
        break;
      }
      printf("%c", c);
    }
    fclose(fp);

    fp = fopen("text.txt", "w+");
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2021);
    fclose(fp);

  } else {
    printf("Parent\n");
    int c;

    while(1) {
      c = fgetc(fp);
      if (feof(fp)) {
        break;
      }
      printf("%c", c);
    }
    fclose(fp);

    fp = fopen("text.txt", "w+");
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2020);
    fclose(fp);
  }



    return 0;
}
