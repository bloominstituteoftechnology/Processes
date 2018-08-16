// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    //Program makes a fork system call and assigns the return of that system call to variable rc

    int rc = fork();

    if (rc < 0 ){
        fprintf(stderr, "fork failed\n");
        exit(1);
        // If rc is less than 0, the fork call has failed, so the program prints a failure message to stderr
    }else if (rc == 0 ){
        printf("Hello!\n");
//If rc is equal to 0, it means that it is in the child process
//The child process then prints a greeting

    }else {
      int wc = waitpid(rc, NULL, 0);
        //wait(NULL);
      printf("Goodbye!\n");
    }
   // The parent process waits until the child process is finished
//The parent process then prints a parting.
    return 0;
}



