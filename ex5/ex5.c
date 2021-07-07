// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 100

// char* msg1 = "hello world #1";
char* msg1 = "What do plumbers always say to customers?";
// char* msg2 = "hello world #2";
char* msg2 = "What?";
// char* msg3 = "hello world #3";
char* msg3 = "Each time you flush a toi­let, you put food in my family’s mouth.";

int main(void)
{
    // Your code here
    char incoming_buffer[MSGSIZE];
    int r_w[2];

    if(pipe(r_w) < 0) {
        fprintf(stderr, "What do plumbers have when they fall asleep?\nPipe Dreams\n");
        exit(1);
    }

    // We need to specify what is going into the write file descriptor
    write(r_w[1], msg1, MSGSIZE);
    write(r_w[1], msg2, MSGSIZE); 
    write(r_w[1], msg3, MSGSIZE);

    for (int i = 0; i < 3; i++) {
        read(r_w[0], incoming_buffer, MSGSIZE); // --> Here we pass the incoming data to be read
        printf("%s\n", incoming_buffer);
    }
    
    return 0;
}
