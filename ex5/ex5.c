// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main()
{
    // Your code here
    int fds[2];
    char buffer[128];

    pipe(fds);

    int child = fork();
        //write from child, read from parent
    if (child < 0)
    {
        printf("Error forking\n");
        exit(1);
    }
    else if (child == 0)
    {
        //write
        write(fds[1], "Hello there!", 14);
    }
    else
    {
        //in parent, read
        wait(NULL);
        read(fds[0], buffer, 128);
        printf("Read from pipe: %s\n", buffer);
    }
    
    return 0;
}
