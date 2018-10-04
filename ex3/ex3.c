/* Write another program using `fork()`. The child process should print "hello"; the parent process should print "goodbye". You should ensure that the child process always prints first. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork(); // create rc variable and set it equal to fork

    if (rc < 0) {    // fork failed
        fprintf(stderr, "fork failed\n"); // error message
        exit(1); // exit 
    } else if (rc == 0) {
        printf("I don't know why you say 'Goodbye', I say 'Hello, hello, hello'.\n");
    } else {
        waitpid(rc, NULL, 0); // https://stackoverflow.com/questions/282176/waitpid-equivalent-with-timeout
        printf("(Hello, goodbye, hello, goodbye. Hello, goodbye.)\n");
    }
    return 0;
}
