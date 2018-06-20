// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//%s is for strings i assume they wanted just the strings and not the pid


int main(int argc, char* argv[])
{
    char CHILE[] = "HELLO\n";
    char PAPS[]="GOODBYE\n";
    char ERR[] ="ERRRRRRRRRRRRRRRRRRRRRRRRRRRR\n";
    // Your code here
    int rc = fork();
 if(rc < 0) {
     printf("%s", ERR);
 }
 else if(rc == 0) {
     printf("%s", CHILE);
 }
    else{
        waitpid(rc, NULL, 0);
        printf("%s", PAPS);
    }
    return 0;
}
