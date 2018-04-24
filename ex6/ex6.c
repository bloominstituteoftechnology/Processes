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

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    struct timespec start, end;
    int diff, sum;
    double avg;
    
    for (int i = 0; i < number_iter; i++) {
      clock_gettime(CLOCK_MONOTONIC, &start);
      write(STDOUT_FILENO, NULL, 0); // https://stackoverflow.com/questions/3866217/how-can-i-make-the-system-call-write-print-to-the-screen?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
      clock_gettime(CLOCK_MONOTONIC, &end);
      diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
      sum += diff;
    }
    avg = sum / (float) number_iter;
    // printf("Time to make a system call: %llu nanoseconds\n", (long long unsigned int) diff); // Prints the elapsed time for a system call
    printf("Average time to make a system call: %f nanoseconds\n", avg);
    return 0;
}
