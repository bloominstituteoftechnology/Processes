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
    char buffer[MSGSIZE];
    int parray[2];
    if (pipe(parray) < 0) {
        fprintf(stderr, "piping of data failed\n");
        exit(1);
    }
    write(parray[1], msg1, MSGSIZE);
    write(parray[1], msg2, MSGSIZE);
    write(parray[1], msg3, MSGSIZE);

    for (int i = 0; i < 3; i++) {
        read(parray[0], buffer, MSGSIZE);
        printf("%s\n", buffer);
    }
    
    return 0;
}
