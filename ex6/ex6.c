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
#include <stdlib.h>
#include <time.h>

#define NUMBER_ITER 1000000
#define BILLION 1000000000L

// int main()
// {
//     uint64_t diff;
//     struct timespec start, end;
//     int i;

//     /* measure monotonic time */
//     clock_gettime(CLOCK_MONOTONIC, &start); /* mark start time */
//     sleep(1);                               /* do stuff */
//     clock_gettime(CLOCK_MONOTONIC, &end);   /* mark the end time */

//     diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
//     printf("elapsed time = %llu nanoseconds\n", (long long unsigned int)diff);

//     /* now re-do this and measure CPU time */
//     /* the time spent sleeping will not count (but there is a bit of overhead */
//     clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); /* mark start time */
//     sleep(1);                                        /* do stuff */
//     clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);   /* mark the end time */

//     diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
//     printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int)diff);

//     exit(0);
// }
int main()
{
    // This the code that does the actual timing.  We will use the timespec struct
    // which comes through the time header file (time.h ^ see above).  These variables
    // will store the startTime and the endTime
    struct timespec startTime, endTime;
    // The sum of all our timings
    long sum = 0;
    // The average - here we use a 'double' - a `float` with even more decimal precision.
    double avg;

    // See string constant `number_iter` defined above.
    // iterates 1 million times
    for (int i = 0; i < NUMBER_ITER; i++)
    {
        // pass in CLOCK_MONOTONIC flag, like in the above link's example
        clock_gettime(CLOCK_MONOTONIC, &startTime);
        printf(""); // Empty string system call per instructions
        // write(fileno(stdout), NULL, 0); // Takes way longer
        clock_gettime(CLOCK_MONOTONIC, &endTime); // log the end time

        // Takes the difference of the two times, then converts to nano-seconds
        long difference = BILLION * (endTime.tv_sec - startTime.tv_sec) + endTime.tv_nsec - startTime.tv_nsec;
        sum += difference;
    }

    avg = sum / (float)NUMBER_ITER; // cast one of the operands to a float in order to get precision

    printf("Average time it takes to make a printf call is %f ns.\n", avg);
    return 0;
}