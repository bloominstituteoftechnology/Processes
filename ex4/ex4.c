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
   int rc = fork(); 
   if(rc < 0){
       fprintf(stderr, "fork failed\n");
        exit(1);
   }else if(rc == 0){
       execl("/bin/ls", "ls", "-l", (char *)0);
   }

    return 0;
}

// The calls with v in the name take an array parameter to specify the argv[] array of the new program.
// The calls with l in the name take the arguments of the new program as a variable-length argument list to the function itself.
// The calls with e in the name take an extra argument to provide the environment of the new program; otherwise, the program inherits the current process's environment.
