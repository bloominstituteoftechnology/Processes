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
#include <stdint.h>	/* for uint64 definition */


#define number_iter 1000000
#define BILLION 1000000000L

int localpid(void) {
	static int a[9] = { 0 };
	return a[0];
}


int main()
{
    uint64_t diff;
	struct timespec start, end;
	int i;
    long long unsigned avg;
    long long unsigned sum=0;

 /* measure monotonic time */
	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
    fprintf( stdout, "" );
	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    

    printf("Only 1 iteration takes %d\n", (int) diff);

    for(i=0; i<1000000; i++){
        /* measure monotonic time */
	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
    fprintf( stdout, "" );
	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */
	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    sum=sum+diff;//update the average 1million times
    }
    avg=sum/1000000;
    printf("This is the avg after 1 million iterations %d\n", (int) avg);
    return 0;
}
