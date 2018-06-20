// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

// 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here    
		printf("pid before fork(): %d\n", (int) getpid());
		int rc = fork();
		// --- child process start here ---

    if (rc < 0) {
      fprintf(stderr, "fork blew up, try again! \n");
      exit(1);
    } else if (rc == 0) {
    	printf("child pid: %d\n", (int) getpid());
    	char *myargs[3]; 

    	myargs[0] = strdup("/bin/ls");
    	myargs[1] = strdup("./");
    	myargs[2] = NULL;

    	// execvp(myargs[0], myargs);
    	execl(myargs[0], myargs[1], myargs[2]);
    	// execle(myargs[0], myargs[1], myargs[2]);
			// execv(myargs[0], myargs); 
    	printf("this should not be seen");
    } else {
    	printf("parent pid: %d\n", (int) getpid());
    }

    return 0;
}
