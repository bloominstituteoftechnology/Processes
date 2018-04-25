// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *text = fopen("text.txt", "w");

    int child = fork();

    if (child < 0) {
      fprintf(stderr, "fork failed...\n");
      exit(1);
    } else if (child == 0) {
      printf("Child processing...\n");
      char str[] = "This is a child string\n";
      fwrite(str, 1, sizeof(str), text);
    } else {
      printf("Parent processing...\n");
      char str[] = "This is a parent string\n";
      fwrite(str, 1, sizeof(str), text);
    }

    fclose(text);

    return 0;
}
