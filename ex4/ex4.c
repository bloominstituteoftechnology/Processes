// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// The exec() family of functions replaces the current process with a new process unlike fork where a copy of the parent(current) process is created.
//execve() executes the program pointed to by the filename. The filename must be either a binary executable or a script starting with a line of the form:

#! interpreter [optional-arg].

//source-https://linux.die.net/man/3/execv



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
        	execv("/bin/ls", (char*) NULL);
	        //execl("/bin/ls", (char*)NULL);	
		printf("Return not expected. Must be an execl() error\n");

	}
	else{
		wait(NULL);
        	printf("This is parent process pid %d\n", getpid());
	}

    	return 0;
}
