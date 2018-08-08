#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("Main process (pid: %d): x equals %d\n", (int)getpid(), x);

    int rc = fork();

    if(rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    
        printf("hello, child here (pid: %d): x equals %d\n", (int) getpid(), x);
        printf("hello, child x %d changing to 20 \n", (int) getpid());
        x = 20;
        printf("child x value is %d (pid: %d)\n",(int) x, getpid());
    } else {
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("hello, parent x %d change to 50\n", (int) getpid());
        x = 50;
        printf("parent x value is %d (pid: %d)\n",(int) x, getpid());
    }

    return 0;
}
