// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

//it's possible to write to the file conccurently. This is because, although it appears that they're writing to the file at the same time, there is actually a brief delay between when the two processes are writing to the file; and so they're not writing to the file at the exact same time.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 

    char *c = "text.txt";
    char *mode = "r+";
    FILE *fp = fopen(c,mode);
    int rc = fork();
    if(rc < 0){
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if (rc == 0){
      printf("writing from child\n");
      int x = 2;
      int *output = &x;
      fwrite(output,sizeof(int),1,fp);
    }
    else{
      printf("writing from parent\n");
      int x = 1;
      int *output = &x;
      fwrite(output,sizeof(int),1,fp);
    }

    fclose(fp);


    
    return 0;
}
