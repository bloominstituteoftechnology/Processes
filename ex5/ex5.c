// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1\n";
char* msg2 = "hello, world #2\n";
char* msg3 = "hello, world #3\n";
 
int main(int argc, char* argv[])
{
    char buff[MSGSIZE];
    int p[2];

    if(fork() == 0){
               
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }else{
        wait(0);
        close(p[1]);
        read(p[0], buff, MSGSIZE);
        printf("%c", *buff); 
        return 0;     
    } 
}