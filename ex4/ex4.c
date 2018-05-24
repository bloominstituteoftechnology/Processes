// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here    
    int rc = fork();
    if(rc < 0){
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if(rc == 0){
      char *args[3];
      args[0] = strdup("/bin/ls");
      args[1] = strdup(".");
      args[2] = NULL;
      execvp(args[0],args);
      printf("error exec call did not work\n");
    }
    return 0;
}
