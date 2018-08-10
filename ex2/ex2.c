// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * fp;
    int c;
  
   fp = fopen("text.txt","r+");
   int rc = fork();

   if (rc < 0) {
       fprintf(stderr, "fork Failed\n");
       exit(1);
   } else if(rc == 0) {
       fprintf(fp, "%s %s %s %d\n", "We", "are", "in", 2018);
   } else {
       fprintf(fp, "%s %s %s %s %d\n", "Let's", "party", "like", "it's", 1999);
   }

 fp = fopen("text.txt", "r");
   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
         break ;
      }
      printf("%c", c);
   }  
   fclose(fp);

   return(0);
}
