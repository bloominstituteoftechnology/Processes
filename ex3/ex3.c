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
    pid_t pid = fork();
    // waitpid(pid, NULL, 0);

    if(pid < 0) {
        fprintf(stderr, "Fork failed!\n");
        exit(1);
    }
    else if(pid == 0) {
        printf("%s", "hello\n");
        // waitpid(pid, NULL, 0);
    }
    else {
        waitpid(pid, NULL, 0);
        printf("%s", "goodbye\n");    
    }

    return 0;
}

/* currently testing out the results of implementing waitpid() in various spots in the code */