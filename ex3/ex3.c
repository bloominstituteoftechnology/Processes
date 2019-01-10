#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

int main(void)
{
   int x = 100;
   int rc = fork();

   //child
   if (rc == 0){
       printf("Child says hello\n");
   } else {
       int wc = waitpid(rc, NULL, 0);
       printf("Parent says goodbuy\n");
   }
   return 0;
}
