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
#define BILLION 1000000000

int main()
{
    // Your code here

//Resources I used:
// http://www.cs.tufts.edu/comp/111/examples/Time/clock_gettime.c
// https://linux.die.net/man/3/clock_gettime
  int i;
  float average;
  long long unsigned int diff;
  struct timespec start, finish;
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (i = 0; i < number_iter; i++);
  {
    printf("");
// haha! I get a warning that there is a zero-length printf string!
// it's by design, really! 
  }
  clock_gettime(CLOCK_MONOTONIC, &finish); 

  diff = BILLION * (finish.tv_sec - start.tv_sec) + finish.tv_nsec - start.tv_nsec;
  average = diff/number_iter;
  printf("Total time is %llu nanoseconds\n", diff);
  printf("Average time is %f nanoseconds\n", average);

    return 0;
}
