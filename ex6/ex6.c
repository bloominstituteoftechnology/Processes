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
#include <time.h> //contains various functions for manipulating date and time including struct timespec

// defining the macros that we will be using in our code
#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    // initializing variables
    struct timespec start, end;
    long sum = 0;
    long difference;
    double avg;

    for (int i = 0; i < number_iter; i++) // one million iterations
    {
        clock_gettime(CLOCK_MONOTONIC, &start); //get time and set it to start

        write(fileno(stdout), NULL, 0); // call an empty write to standard out

        clock_gettime(CLOCK_MONOTONIC, &end); // get time and set it to end

        difference = BILLION * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec); //use start and end values to find the elapsed time
        sum += difference;
    }

    avg = sum / (float)number_iter; // average of all the iterations in nanoseconds

    printf("Average time it takes to make a system call is %f ns.\n", avg);

    return 0; // needs to return an integer
}
