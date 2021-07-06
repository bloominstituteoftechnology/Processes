// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t cp = fork();

    if (cp < 0) {
        printf("Error: Failed to fork!\n");
        exit(1);
    } else if (cp == 0) {
        printf("Child says... 'ello!\n");
    } else {
        waitpid(cp, NULL, 0);        
        printf("Parent says... See ya!\n");
    }
    return 0;
}
