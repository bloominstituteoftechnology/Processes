// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int responseFromFork = fork();
    if (responseFromFork < 0) {
        printf("You forked up!\n");
        exit(1);
    } else if (responseFromFork == 0) {
        printf("There is no pain: you are receding!\n");
    } else {
        sleep(2);
        printf("A distant ship - smoke on the horizon!\n");
        responseFromFork = fork();
        if (responseFromFork == 0) {
            sleep(2);
            printf("You are only coming through in waves. . .\n");
        } else {
            sleep(4);
            printf("Your lips move, but I can't hear what you're saying\n");
        }
    }
    
    return 0;
}
