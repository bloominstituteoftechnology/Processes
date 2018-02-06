// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE * fp;
    
    fp = fopen("tex.txt", "w");
    fprintf(fp, "%s", "This is point 1 before fork. \n");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        fclose(fp);
        exit(1);
    } else if (rc == 0){
        fprintf(fp, "%s", "this is after for one. the else if and rc == 0. \n");
        
    } else {
        fprintf(fp, "%s", "this is else after fork as welland fuck the fork at else\n");
    }

    fclose(fp);

    //FILE *fp;
   int c;
  
   fp = fopen("tex.txt","r");
   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);
    
    return 0;
}

//    // Your code here
//     int x = 100;

// printf("hello world (pid: %d) the value of x is at first is %d. \n", (int) getpid(), x);
//     // child process starts executing here
//     int rc = fork();
//     if (rc < 0) {    // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {    // child process satisfies this branch
//     x++;
//         printf("hello, child here (pid: %d) and the value of x++ is %d \n.", (int) getpid(), x);
//     } else {
//         x--;
//         printf("hello, parent here (pid: %d) of child %d and the value of x -- is %d\n", (int) getpid(), rc, x);
//     }