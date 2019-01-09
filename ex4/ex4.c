// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
   int rc = fork(); //starting the child process
   if (rc < 0) {
       fprintf(stderr, "fork failed\n"); //error handling
       exit(1);

   } else if ( rc == 0){
       printf("Child running\n");
       char *myargs[2];
       myargs[0] = strdup("/bin/ls");//douplicate the strng
       myargs[1] = NULL;


       execvp(myargs[0], myargs);
   } else {
       waitpid(rc, NULL, 0);//Wait for a specific child process to end
       printf("Child done\n");
       char *myargs[2];
       myargs[0]= strdup("/bin/ls");//douplicate the strng
       myargs[1] = NULL;
       execv(myargs[0], myargs);

   }

    return 0;
}
