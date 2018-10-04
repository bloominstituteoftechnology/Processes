// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here    
        int rv = fork();
     if(rv < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rv == 0)
    {
        char *myargsl[] = {"ls", (char *) 0};
        char *myargsv[] =  {"/bin/ls", NULL};
        //execl("/bin/ls", "ls", myargsl[1]);
        // execv("/bin/ls", myargsv);
        execle("/bin/ls", "/bin/ls", myargsl[1]);
    }
    else
    {
        int wc = waitpid(rv, NULL, 0);
    } 

    return 0;
}
