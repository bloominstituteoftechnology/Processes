#include <stdio.h> //Enables the use of input and output functions
#include <stdlib.h>// Enables the use of several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <unistd.h>//Enables the use of a ton of different fuctions but the ones I could find that we have used are folk and Null pointer

int main(void){
    int x = 100; // Initizatng x to 100
    printf("Variable x = %d\n", x);//Printing out x
    int rc = folk();
// Child proccess starts executing here
    if (rc < 0){ //If folk fails exit
        fprintf(stderr, "Folk has failed\n");
        exit(1);
    }
    else if (rc == 0){ //If child branch is satified this executes
        printf("Hello, Im the child\n");
        printf("Child x = %d \n", x);
        x = 18;
    }
    else{//Excutes the parent process
        printf("Hello Im the Parent of the child \n", x);
        x = 90;
    }
    printf("Variable x = %d \n", x, (int)getpid());//Prints out the process id along with the value of x
    return 0;
}