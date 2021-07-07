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
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

// Sean's solution-----------
int main()
{   
    struct timespec start, end;
    long sum = 0;
    long difference;
    double avg;

    for (int i = 0; i < number_iter; i++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        printf("Some string\n");
        clock_gettime(CLOCK_MONOTONIC, &end);

        difference = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
        sum += difference;
    }

    avg = sum / (float) number_iter;

    printf("Average time it takes to write to stdout is %f ns.\n", avg);

    return 0;
}


// code from examplelink ------
// main(int argc, char **argv)
// {  
// 	uint64_t diff;
// 	struct timespec start, end;
// 	int i;

// 	/* measure monotonic time */
// 	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
// 	sleep(1);	/* do stuff */
// 	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

// 	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
// 	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

// 	/* now re-do this and measure CPU time */
// 	/* the time spent sleeping will not count (but there is a bit of overhead */
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */
// 	sleep(1);	/* do stuff */
// 	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

// 	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
// 	printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int) diff);

// 	exit(0);
// }
