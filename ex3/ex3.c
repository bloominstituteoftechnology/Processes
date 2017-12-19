// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    // Your code here
    int cpid = fork();
    if(cpid == 0){
        puts("HELLO");
    }else{
        wait(0);
        puts("GOODBYE");
    }
    return 0;
}
