// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    

printf("Main process (pid: %d)\n", (int)getpid());
 
  int child = fork();

  if (child < 0)
  {
    fprintf(stderr, "Fork failed\n");
    exit(1);
  }
  else if (child == 0)
  {
    printf("Child process (pid: %d)\n", (int)getpid());
    printf("Transforming child process into list command...\n");
  char *myargs[3];
    myargs[0] = "ls";
    myargs[1] = "-a";
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
    printf("My eyes must not see this.");
  }
  else
  {
    printf("Parent process (pid: %d) of child %d\n", (int)getpid(), child);
  }
    return 0;
}


// - Ex4 shows variant exec() system calls. Each achieves the same thing but takes different input format:
// - execl() takes the full path of the file to execute and a list of arguments to be passed to the file. The list also starts with the file name and ends with NULL.
// - execlp() takes file name and the same type of argument list as execl()
// - execv() takes the full path of the file to execute and an array of arguments. The first element in the array is the file name and the last element is NULL.
// - execvp() takes the file name with subcript of the first element and the same type of argument array as execv()