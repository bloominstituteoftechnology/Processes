// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        char *hello = "hello";
        printf("%s\n", hello);
        exit(0);
    }

    // printf("Parent waiting for child to to greet");
    char *goodbye = "goodbye";
    wait(NULL);
    printf("%s\n", goodbye);

    return 0;
}
