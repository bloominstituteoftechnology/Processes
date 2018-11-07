// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

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
printf("About to run ls\n");
execlp("ls", "ls", "-aF", ".", (char*)0);
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