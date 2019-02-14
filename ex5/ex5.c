// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16 

char* msg1 = "hello world #1"; 
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
        // Write a program that forks a child and creates a shared pipe
        // between the parent and child processes.
        int fd[2];
        
        pid_t   childpid;
                
        char* msg1 = "hello world #1"; 
        char* msg2 = "hello world #2";
        char* msg3 = "hello world #3";
        char  readbuffer[80];

        pipe(fd);
        
        if((childpid = fork()) == -1) {
                perror("fork");
                exit(1);
        }

        if(childpid == 0) {
               // Have the child write  the three messages to the parent
                printf("In the child writing\n");
                close(fd[0]);

                write(fd[1], msg1, MSGSIZE);
                write(fd[1], msg2, MSGSIZE);
                write(fd[1], msg3, MSGSIZE);
                exit(0);
        }
        else {
                printf("In  parent.. process  reading\n");
                close(fd[1]);
                //the parent print out the messages. 
                for (int i = 0;  i < 3; i++){
                    read(fd[0], readbuffer, MSGSIZE); // READ Pipe
                    printf("%s\n", readbuffer); 
                }
        }
        
        return 0;
}
