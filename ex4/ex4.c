// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// there are so many variants of the exec() call because we don't know how many parameters...
	// ...will need to be passed to the external function that we are executing

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
    printf("forking...\n");

    // program calls fork()
    int rc = fork();

    if (rc < 0) {
    	printf("fork failed\n");
    	exit(1);
    } else if (rc == 0) {
    	printf("CHILD EXECUTING:\n");
    	char *argv[] = { "/bin/ls", "-1", 0};
    	// call some form of exec() to run the program /bin/ls
    	execv(argv[0], argv);
    	execvp(argv[0], argv);
    } else {
    	int wc = waitpid(rc, NULL, 0);
    	printf("PARENT EXECUTING\n");
    }


    return 0;
}
