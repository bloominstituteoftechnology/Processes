// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
   int rc = fork();
   char *args[2];

   if (rc < 0) {
       printf("Fork failed\n");
       exit(1);
   }else if (rc == 0) {
       args[0] = "/bin/ls";
       args[1] = NULL;
       execvp(args[0], args);
   }else {
       int wc = waitpid(rc, NULL, 0);
       printf("This is the parent\n");
   }

    return 0;
}
