// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    char *c = "Hello";
    char *p = "Goodbye";
int rc =fork();
if (rc <0)
{
    fprintf(stderr,"failed fork\n");
}
else if(rc == 0)
{
printf("Child: %s\n",c);
}
else
{
int wc = waitpid(rc,NULL,0);
printf("Parent: %s\n",p);
}
    return 0;
}
