// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1\n";
char* msg2 = "hello world #2\n";
char* msg3 = "hello world #3\n";

int main(void)
{
    // Your code here
    pid_t pid = fork();
    char* messages[sizeof MSGSIZE * 3];
        messages[0] = msg1;
        messages[1] = msg2;
        messages[2] = msg3;
    
    if (pid == 0) {
            for(int i = 0; i < 2; i++) {
                write(STDOUT_FILENO, messages[i], 128 );
            }
    } else {
        printf("parent stuff");
    }
    
    return 0;
}
