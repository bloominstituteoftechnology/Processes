#include <stdio.h> //Enables the use of input and output functions
#include <unistd.h>//Enables the use of a ton of different fuctions but the ones I could find that we have used are folk and Null pointer
#include <stdlib.h>// Enables the use of several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.

int main(void){
    FILE * fileprint;//Not really sure. I know this is pointer to the file that we want to reference. What I think this is doing is marking this fileprint as a datatype that c can understand

    fileprint = fopen("text.txt", "w+"); //Opening files and flaging it for writing
    int rc = folk(); //Folking and starts executing here child process
    if(rc = 0){
        printf("Folk has failed\n");
        exit(1);
    }
    else if(rc == 0){

    }
}
