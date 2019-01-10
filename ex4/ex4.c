// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
   	int rc = fork();
   	if (rc < 0){
   		exit(1);
   	} else if (rc == 0){
   		char *myargs[2];
   		myargs[0] = strdup("ls");
   		myargs[1] = NULL;
   		execvp(myargs[0],myargs);
   		// execlp("ls","ls",NULL);
   	} else {
   		waitpid(rc,NULL,0);
   		printf("complete");
   	}

    return 0;
}
