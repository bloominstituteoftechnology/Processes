// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the
// `clock_gettime` procedure to time how long a single system call takes. It'll
// do this for one million iterations, and then find the average of all of those
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
// While the linked site does say that `clock_gettime()` does not work on OSX, this
// turns out to only be the case for OSX versions < 10.12. Anything later than that
// and `clock_gettime()` should work just fine.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{

    // Your code here
    struct timespec start, end; // Create 2 structs for Start and End Timers.
    long long unsigned int diff;
    long long unsigned int added;
    long long unsigned int average;
    int i = 0;

    for (; i <= number_iter; i++)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); // Clock in before running.
        write(1, "", 0);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); // Clock out after running.
        // Add all the runtimes up to 1mil iterations.
        added = added + (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    }
    // Print how long it all took in total.
    printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int)added);
    // Get the total times added and divide it by number of iterations to get the avg.
    average = added / number_iter;
    // Print out the average time for 1 call to run.
    printf("The average time it takes for a single system call is: %llu nanoseconds\n", average);
    return 0;
}
