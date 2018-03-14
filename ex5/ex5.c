// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 


//https://www.youtube.com/watch?v=uHH7nHkgZ4w  3min tutorial
//https://www.youtube.com/watch?v=bouXriz6oQ0&feature=youtu.be Ls exercises lecture this 
//one 1h14

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
    int pipe1[2]; // create your file descriptors which by default fds[1] is writing and [0]reading
    int pipe2[2];
    char buffer[128];
    pipe(pipe1);
    pipe(pipe2);
    int forked = fork();

    if (forked < 0) { 
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (forked == 0) {
        write(pipe1[1],"Hello, World!", 14);
        read(pipe2[0],buffer, 128);
         printf("child read from pipe2: %s\n", buffer);
    } else {
        //wait(NULL);  // wait for child process to put message into pipe
                     // actually if there is nothing to read on line 37 this process will
                     // sleep and the child process will run so no need to wait really
        read(pipe1[0],buffer, 128);
        write(pipe2[1],"Thanks", 7);

        printf("read from pipe1: %s\n", buffer);
    }
    
    
    return 0;
}
