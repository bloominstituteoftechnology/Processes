// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
   if (fork() == 0)
   {
       printf("Hello\n");                    //this is the child
   }
    else
   {
       int stat_loc;
       wait(&stat_loc);
       printf("Child status: %d\n", WEXITSTATUS(stat_loc));
       printf("Goodbye\n");                 //this is the parent
   }

    return 0;
}
