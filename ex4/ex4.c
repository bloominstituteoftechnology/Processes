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
    	printf("hello world (pid: %d)\n", (int) getpid());

    	pid_t pid;    
	pid=fork();

	if(pid<0){             // fork failed; exit
        fprintf(stderr, "fork failed\n");    //stderr is standard error stream and is the default destination for error messages and other diagnostic warnings
        exit(1);
		
	}
	else if(pid==0){
		printf("This is child process pid %d\n", getpid());
        	execl("/bin/ls", "ls", NULL);   
		printf("Return not expected. Must be an execl() error");

	}
	else{
		wait(NULL);
        	printf("This is parent process pid %d\n", getpid());
	}

    	return 0;
}
