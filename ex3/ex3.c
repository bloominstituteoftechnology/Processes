// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int x = 100;
    int rc = fork();

    //child
    if (rc == 0){
        printf("Child says hello\n");
    } else {
        // parent
        int wc = waitpid(rc, NULL, 0); // ensure that the child executes before parent
        printf("Parent says goodbuy\n");
    }

    return 0;
}
