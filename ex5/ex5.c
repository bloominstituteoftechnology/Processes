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
    int new_pipe[2];
    pipe(new_pipe);
    int new_fork = fork();

    if (new_fork < 0) {
        printf("Fork failure!\n");
        exit(1);
    } else if (new_fork == 0) {
        printf("Hitting the child process\n");
        write(new_pipe[1], msg1, MSGSIZE);
        write(new_pipe[1], msg2, MSGSIZE);
        write(new_pipe[1], msg3, MSGSIZE);
    } else {
        waitpid(new_fork, NULL, 0);
        printf("Hitting the parent process\n");
        for (int i = 0; i < 3; i++) {
            char buffer[MSGSIZE];
            read(new_pipe[0], buffer, MSGSIZE);
            printf("%s\n", buffer);
        }

    }
    return 0;
}
