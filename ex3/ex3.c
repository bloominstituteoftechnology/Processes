// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    printf("Hello, process! (pid: %d).\n", (int) getpid());
    pid_t pid = fork();
    if (pid < 0) {
        printf("Forking failed!");
    } else if (pid == 0) {
        printf("Hello! (pid: %d).\n", (int) getpid());
    } else {
        int wc = waitpid(pid, NULL, 0);
        printf("Goodbye! (pid: %d) (child: %d).\n", (int) getpid(), pid);
    }

    return 0;
}


