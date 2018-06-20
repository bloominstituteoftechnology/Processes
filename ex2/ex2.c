// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *fp;
    fp = fopen("text.txt","r");

    int c;
    int rc = fork();
    
    if (rc < 0) { // Fail
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc == 0) { // Child
      printf("- Child -\n");
      // Must reopen file for child fork
      while(1) {
        c = fgetc(fp);
        if(feof(fp)) break;
        printf("%c", c);
      }
    } else { // Parent
      printf("- Parent -\n");
      // Accesses file on the parent fork
      while(1) {
        c = fgetc(fp);
        if(feof(fp)) break;
        printf("%c", c);
      }
    }
    puts("\n");

    return 0;
}
