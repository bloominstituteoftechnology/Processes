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
#include <unistd.h>
#include <time.h> // for clock_gettime

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // "bench marking" aka getting the run time of system calls...
    // time a bunch of iterations and get the average time
    struct timespec startTime, endTime;
    long sum = 0;
    double avg;

    // number_iter for 1000000 times defined above
    for (int i = 0; i < number_iter; i++) {
        // logs start time
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        // printing and empty string
        printf("");
        // logs end time
        clock_gettime(CLOCK_MONOTONIC, &endTime);
        // get the difference between the 2 times, and then convert to nanoseconds
        long difference = BILLION * (endTime.tv_sec - startTime.tv_sec) + endTime.tv_nsec - startTime.tv_nsec;
        // add diff to sum
        sum += difference;
    }
    // figuring the avg
    avg = sum / number_iter;
    printf("Average time to make printf call is %f\n", avg);
 
    return 0;
}
