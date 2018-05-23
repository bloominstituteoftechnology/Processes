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
    char messages[MSGSIZE];
    int p[2], read_messages;
    pid_t rc;

    if (pipe(p) < 0) {
        fprintf(stderr, "Pipe failed, exiting\n");
        exit(1);
    } 
    
    rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed, exiting\n");
        exit(1);
    } else if (rc > 0) {
        printf("Child writing to pipe...\n");

        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        close(p[1]);

        printf("Parent printing messages:\n");

        while ((read_messages = read(p[0], messages, MSGSIZE)) > 0) {
            printf("    %s\n", messages);
        }
        printf("End of messages\n");
    }
    return 0;
}
