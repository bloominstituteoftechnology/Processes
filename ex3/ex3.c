// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char * c_says = "hello";
    char * p_says = "goodbye";

    pid_t pid = fork();

    if (pid != 0){
        int wc = waitpid(pid, NULL, 0);
        printf("Parent says, %s\n", p_says);
        
    } else{
        printf("Child says, %s\n", c_says);
    }

    return 0;
}
