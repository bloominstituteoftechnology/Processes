// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>  // installing the necessary header files
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char inbuf[MSGSIZE];    // initialize inbuf takin in the message size
    int p[2];   // an array to hold the file pointers for read and write

    if (pipe(p) < 0) {  // call pipe() passing in p, if p is less than zero
        fprintf(stderr, "pipe failed\n");   // print error message if p is less than 0
        exit(1);    // exit passing in 1 (exit code) to help identify error is from pipe failure 
    }

    int rc = fork();    // fork function: creates a new process by duplicating the calling process. Child process is created. 

    if (rc < 0) {   // handling error during fork()
        fprintf(stderr, "forked failed\n"); // error message if fork failed
        exit(2);    // exit passing in 2 (exit code) to help identify error is from fork failure 
    } else if (rc == 0) {   // on successful forking, run this child process 
        printf("child writing to pipe\n");  // child writing to pipe
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    } else {
        int wc = waitpid(rc, NULL, 0);  // call wait function on parent
        close(p[1]);    // close the write end/pipe
        printf("parent reading from pipe\n");   // print this for parent

        while (read(p[0], inbuf, MSGSIZE) > 0) { // read will return the number of bytes it has read, will read in chunks as set by message size, and will keep reading as long as there are still messages
            printf("%s\n", inbuf);
        }

        printf("finished reading\n");   // print after parent is done reading
    }

    return 0;
}
