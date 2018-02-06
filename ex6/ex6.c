// Write a program that will find the average time it takes for your computer
// to make a system call an empty write to stdout. Your program should use the 
// `clock_gettime` procedure to time how long a single system call takes. It'll 
// do this for one million iterations, and then find the average of all of those 
// iterations in nanoseconds.
// For some helpful documentation and examples of using time-related system calls,
// visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    struct timespec start, end;
    long long unsigned int diff;
    FILE* pFileHandle;
    long long unsigned int totalDiff;
    
    for (int i = 0; i <= number_iter; i++) {
    // todo: add all results together and divide by by number of iterations
    clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
	// pFileHandle = stdout;	/* do stuff */
	fprintf(stdout, "");
    clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    totalDiff += diff;
    }

    totalDiff = totalDiff/number_iter;
    printf("average elapsed time from %llu iterations: %llu nanoseconds\n", number_iter, totalDiff);
    return 0;
}
