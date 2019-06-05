// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16
#define BUFF_SIZE 128
char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(int argc, char * argv[])
{
    // Your code here

    char buf[128];

    // fd[0] READ end of the pipe 
    // fd[1] WRITE end of the pipe
    int fd[2]; // file descriptor

    pipe(fd);

    if (!fork()) { // child process
        close(1);
        dup(fd[1]);
        close(fd[0]);
        printf("yooooo");
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);
    } else {     // parent process
        close(0);
        dup(fd[0]);
        close(fd[1]);
        char read_buf[100];
        read(fd[0], read_buf, MSGSIZE);
        printf("\"%s\" \n", read_buf);
        read(fd[0], read_buf, MSGSIZE);
        printf("\"%s\" \n", read_buf);
        read(fd[0], read_buf, MSGSIZE);
        printf("\"%s\" \n", read_buf);
    }

    // char inBuff[BUFF_SIZE];
    // char aBuff[BUFF_SIZE];
    // // fgets(aBuff, BUFF_SIZE, fd[0]);

    // int bytes_written = write(fd[1], "We come in peace\n", 17);

    // int bytes_read = read(fd[0], buf, sizeof(buf));

    // // write(STDOUT_FILENO, aBuff, bytes_read);
    // write(STDOUT_FILENO, buf, bytes_read);

    return 0;
}