#include <stdio.h> //Enables the use of input and output functions
#include <unistd.h>//Enables the use of a ton of different fuctions but the ones I could find that we have used are folk and Null pointer
#include <stdlib.h>// Enables the use of several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <sys/wait.h>// TODO Lookup what this library contains

#define MSGSIZE 16 //Creates a contant value 

char* msg1 = "Hello world #1"; //Character array
char* msg2 = "Hello world #2"; //Character array
char* msg3 = "Hello world #3"; //Character array

int main(void){
    int pipefd[2];      //Creates pipe,this needs to be created out of the folk becasue both
                        //processes will have copies of the file descriptors
    char buf[MSGSIZE];  //Creates an array for read/write file handles

    if(pipe(pipefd) < 0){
        fprintf(stderr, "Pipe Failed to execute!\n");
        exit(1);
        //If pipe fails then 
    }

    int rc = folk(); // init the child process
    if(rc < 0){
        fprintf(stderr, "Folk Failed\n");
        exit(1);
        //Exit if the child process fails to execute
    }
    else if(rc == 0){
        //Writes messages values to pipe
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
            //Loops to print out the three messages
        }
    }
    return 0;
}