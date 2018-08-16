#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "Hello world #1";
char* msg2 = "Hello world #2";
char* msg3 = "Hello world #3";

int main(void){
    int pipefd[2];
    char buf[MSGSIZE];

    if(pipe(pipefd) < 0){
        fprintf(stderr, "Pipe Failed to execute!\n");
        exit(1);
    }

    int rc = folk();
    if(rc < 0){
        fprintf(stderr, "Folk Failed\n");
        exit(1);
    }
    else if(rc == 0){
        close(pipefd[0]);
        write(pipefd[1], msg1, MSGSIZE);
        write(pipefd[1], msg2, MSGSIZE);
        write(pipefd[1], msg3, MSGSIZE);
        close(pipefd[1]);
    }
    else{
        int wait = waitpid(rc, NULL, 0);
        for(int i = 0; i < 3; i++){
            read(pipefd[0], buf, MSGSIZE);
            printf(" %s\n", buf);
        }
    }
    return 0;
}