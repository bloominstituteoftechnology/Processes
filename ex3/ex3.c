// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//https://www.geeksforgeeks.org/wait-system-call-c/

// int main()
// {
//     pid_t cpid;
//     if (fork() == 0)
//         exit(0);  //end child process
//     else
//         cpid = wait(NULL);
//     printf("Parent pid = %d\n", getpid());
//     printf("Child pid = %d\n", cpid);
//     return 0;
// }


int main(void)
{
    int rc = fork();

    if(rc<0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        printf("hello, pid = %d\n", getpid());
    }else {
        wait(NULL);
        printf("goodbye, pid = %d\n", getpid());
    }
    return 0;
}
