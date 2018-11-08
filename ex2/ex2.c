// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
   FILE *fp = fopen("text.txt", "w");
   int r = fork();
   if (rc < 0) {    // fork failed; exit
      printf(stderr, "fork failed\n");
      exit(1);
   }

   else if (r == 0)
   {
       printf("child (pid: %d); x = %d \n", (int) getpid(), x);
   }

   else 
   {
       printf("parent (pid: %d); x = %d \n", (int) getpid(), x);
   }
   
   fclose(fp);
    
    
    return 0;
}
