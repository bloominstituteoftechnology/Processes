// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork blew up, try again! \n");
        exit(1);
    }
        else if (rc == 0) {
            printf("I am a child!\n");  
        } else {
            int wc = waitpid(rc, NULL, 0);
            printf("I'm a parent and I should be going second!\n");
        }
    return 0;

    // Your code here
		// int rc = fork();
		// // --- child process starts here ---
		// if (rc < 0)
	  // {
	  //   fprintf(stderr, "Fork blew up! Try again \n");
	  //   exit(1);
	  // }
	  // else if (rc == 0)
	  // {
	  // 	printf("hello\n");
	  // 	printf("child pid %d\n", (int) getpid());
	  // } else {
	  // 	int wc = waitpid(rc, NULL, 0); // wait for child process to finish
	  // printf("waitpid returns child pid: %d\n", wc);
	  //   printf("goodbye\n");
	  // }

	 	//  return 0;

	// // Your code here
    // int rc = fork();
    // // Child process starts here
    // if (rc < 0)
    // {
    //     fprintf(stderr, "Fork failed\n");
    //     exit(1);
    // }
    // else if (rc == 0) // Child process prints Hello
    // {
    //     printf("Hello from child process!\n");
    // }
    // else // Parent process prints goodbye
    // {
    //     int wc = waitpid(rc, NULL, 0); // wait() suspends parents to print after child
    //     printf("Goodbye from parent process!\n");
    // }

    // return 0;
}
