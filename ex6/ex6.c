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
  // Your code here
	struct timespec start, end;
	uint64_t diff;
 	// use monotonic clock to measure elapsed time
	// start clock
	clock_gettime(CLOCK_MONOTONIC, &start);
	// iterate 1 million times - make an empty write to stdout
	for (int i = 0; i < number_iter; i++) {
		printf("");
	}
	// end clock
	clock_gettime(CLOCK_MONOTONIC, &end);
	// print the elapsed time from start to end
	// convert seconds to nano-seconds
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

	int average = diff / number_iter;
	printf("averagee: %d\n", average);
  return 0;
}
