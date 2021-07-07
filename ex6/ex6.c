/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#define number_iter 100000
#define BILLION 1000000000L

//edited with solution lecture
int main () 
{ 
    struct timespec start, finish; 
    //long double average, total; 
    long sum = 0;
    long difference;
    double avg;

    // chew up some CPU time
    for (int i = 0; i < number_iter; i++) { 
    clock_gettime(CLOCK_MONOTONIC, &start); 
        // write(fileno(stdout), NULL, 0);
        printf("");
        // getpid();
    clock_gettime(CLOCK_MONOTONIC, &finish); 
    difference = BILLION * (finish.tv_sec - start.tv_sec) + finish.tv_nsec - start.tv_nsec;
    sum += difference;
    }     
    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
    
    // if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	// --seconds; 
	// //ns += 1000000000; 
    // } 
    avg = sum / (float) number_iter;
    printf("seconds without ns: %ld\n", seconds); 
    printf("nanoseconds: %ld\n", ns); 
    printf("diff: %ld\n", difference); 
    printf("avg time per write: %f ns\n", avg);

} 
