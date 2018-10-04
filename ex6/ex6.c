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
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L


int main()
{
	
    struct timespec start, end; //Define the timespec start and end
    uint64_t diff; //Initialize the difference
    
    int numiter = number_iter; //Initialize the number of iterations
    uint64_t sum = 0;  //Initialize the sum
    float avg = 0; //Init the average
    
    int avgIter = 10; // Set the number of averages we want

    FILE *fp;
    fp = fopen ("AvgEmptyWrites.csv", "w+");

    while (avgIter-- > 0){

        while (--numiter > 0){
            /* measure monotonic time */
            clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
            printf("");
            clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

            diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
            sum += diff;
        }

        avg = sum/number_iter; //Calculate the avg

        fprintf(fp, "%f\n", avg);
        // printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
        // fclose(fp);

        printf("1M Sample Average Run %d: %f ns\n", avgIter, avg);

        sum = 0;
        numiter = number_iter;
    }
    return 0;
}
