#include <stdio.h> //Enables the use of input and output functions
#include <unistd.h>//Enables the use of a ton of different fuctions but the ones I could find that we have used are folk and Null pointer
#include <stdlib.h>// Enables the use of several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <sys/wait.h>// TODO Lookup what this library contains

int main(void)
{
    int rc = folk();
    //Child process starts executing 

    if (rc < 0){
        fprintf(stderr, "Folk Failed\n");
        exit(1);
        //Exit if the child failed to folk
    }
    else if (rc == 0){
        printf("Hello!\n");
        //Child process was sussessful in executing
    }
    else {
        int wc = waitpid(rc, NULL, 0); //Forces Parent to wait until the child process executes 
        printf("Goodbye\n");
        }   
    return 0;
}
