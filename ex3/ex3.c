// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    // Your code here

pid_t ChildPid;
time_t now;
time(&now);

  
   
 ChildPid = fork();
  
  if(ChildPid == 0)
  {
printf("Today is : %s", ctime(&now));
printf("Child %d\n", ChildPid);
 printf("Getpid %d\n", (int) getpid());
printf("Child PID printing ==> Hello\n");

exit(0);

  }
  else if(ChildPid < 0)  // fork failed 
{    
   printf("fork failed");
}

else{

int returnStatus;    
    waitpid(ChildPid, &returnStatus, 0);


if (returnStatus == 0){
   printf("Today is : %s", ctime(&now));
   printf("Getppid %d\n", (int) getppid());
   printf("Parent printing ==> Goodbye\n");
   }
    return 0;
}
}