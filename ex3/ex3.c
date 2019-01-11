// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{

int x = fork();

if(x==0){
    printf("%s","hello");
}
else{
    int wc = waitpid(x, NULL, 0);
    printf("%s","goodbye");
}
    return 0;
}
