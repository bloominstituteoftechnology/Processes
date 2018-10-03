// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    char hello[] = "hello";
    char goodbye[] = "goodbye";
    int status;

    int rc = fork();

    if(rc < 0){
        printf("fork failed\n");
        exit(1);
    }else if (rc == 0){
        printf("%s ", hello);
    }else{
        waitpid(rc, &status, 0);
        printf("%s\n", goodbye);
    }


    return 0;
}
