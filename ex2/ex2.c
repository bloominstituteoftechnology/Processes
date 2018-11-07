// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>


int main(void)
{
    // Your code here 
FILE * fp;
pid_t pid;
time_t now;
time(&now);

   fp = fopen ("text.txt", "a");
   fprintf(fp,"Tody is : %s", ctime(&now));
   fprintf(fp, "%s %s %s %d\n", "parent PID written", "to", "on Nov 11", 2018);
   pid = fork();
   wait(100);
   fprintf(fp,"Tody is : %s", ctime(&now));
   fprintf(fp, "%s %s %s %d\n", "written", "to from child", "on Nov 11", 2018);

   fclose(fp);
    return 0;
}
