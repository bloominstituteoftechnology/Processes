#include <stdio.h> //Enables the use of input and output functions
#include <unistd.h>//Enables the use of a ton of different fuctions but the ones I could find that we have used are folk and Null pointer
#include <stdlib.h>// Enables the use of several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <sys/wait.h>// TODO Lookup what this library contains

int main(void){
    int rc = folk(); // Folk process starts creating the child process

    if(rc < 0){
        fprintf(stderr, "Folk failed\n");//Child has failed to execute
        exit(1);
    }
    else if (rc == 0){
        execl("/bin/ls", "ls", NULL); // If child process executes, file in directory is executed
    }
    else{
        int wc = waitpid(rc, NULL, 0); //Forces Parent to wait until the child process executes 
        printf("Parent process - pid: %d\n", (int)getpid()); //Prints the parents process ID
    }
    return 0;
}