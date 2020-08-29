#include <stdio.h> //Enables the use of input and output functions
#include <unistd.h>//Enables the use of a ton of different fuctions but the ones I could find that we have used are folk and Null pointer
#include <time.h>// TODO Lookup what this library contains

#define number_iter 1000000
#define BILLION 1000000000L

int main(void){

    FILE * fp;
    fp = fopen("./ex6/text.txt", "w");

    struct timespec start, end;
    int i;
    long long unsigned int diff;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i < number_iter; i++){
        fprintf(fp, "");

    };

    clock_gettime(CLOCK_MONOTONIC, &end);

    diff = (BILLION*(end.tv_sec-start.tv_sec) + end.tv_nsec-start.tv_nsec)/number_iter;
    printf("Average time: %llu\n", diff);

    return 0;
}