// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// the variants on exec relate to which types of parameters you're passing to the executed program. Like, are you passing an individual parameter, or an array or a variable? L usually refers to individual parameters, V to arrays and variables, and I think E refers to environment variables but I could be wrong about that.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
  int rc = fork();

  if (rc < 0)
  { 
    fprintf(stderr, "fork failure alert!\n");
    exit(1);
  }
  else if (rc == 0)
  {
//    execv("/bin/ls", "ls");
//    execv is looking for an argument with an array and I'm not sure what to pass here since we're just trying to do ls
    execl("/bin/ls", "ls", NULL);
// apparently, you need a null variable for execl: https://stackoverflow.com/questions/3816778/not-enough-variables-to-fit-a-sentinel
  }
  else
  {
    int wc = waitpid(rc, NULL, 0);
    printf("Parent process - pid: %d\n", (int)getpid());
  }
  
    return 0;
}
