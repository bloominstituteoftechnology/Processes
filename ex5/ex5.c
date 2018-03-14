// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MSGSIZE 16

char* msg1 = "hello world #1\n";
char* msg2 = "hello world #2\n";
char* msg3 = "hello world #3\n";

int main()
{
    // Your code here
   
    int fds[2];
    char buffer[128];
    pipe(fds);
    pid_t pid = fork();
    if(pid == 0){
        write(fds[1],msg1, strlen(msg1));
        write(fds[1],msg2, strlen(msg2));
        write(fds[1],msg3, strlen(msg3));
        printf("Read from children\n");        
    } else {
        wait(NULL);
        read(fds[0], buffer, 128);
        printf("Read from parent part of pipe:\n%s\n", buffer);
    }
    
    return 0;
}
