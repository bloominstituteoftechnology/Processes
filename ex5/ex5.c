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
    int fd[2]; // init pipe array
    pipe(fd); // init the pipe

    pid_t pid = fork(); // init the fork


    char* messages[sizeof MSGSIZE];
    int buf[128];
        messages[0] = msg1;
        messages[1] = msg2;
        messages[2] = msg3;        
    
    if (pid < 0) {
        perror("fork failed\n");
        exit(1);
    } else if (pid == 0) {
        write(fd[1], messages[0], sizeof messages[0]);
        write(fd[1], messages[1], sizeof messages[1]);
        write(fd[1], messages[2], sizeof messages[2]);
    } else {
        wait(NULL);
        read(fd[0], messages[0], sizeof buf);
        read(fd[0], messages[1], sizeof buf);
        read(fd[0], messages[2], sizeof buf);
    }
    
    return 0;
}
