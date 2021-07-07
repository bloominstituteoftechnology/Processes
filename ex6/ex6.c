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

// int main()
// {
//     // Your code here
    
//     return 0;
// }

int identity(int x) { return x; }
 
int sum(int s)
{
  int i;
  for(i=0; i < 1000000; i++) s += i;
  return s;
}
 
#ifdef CLOCK_PROCESS_CPUTIME_ID
/* cpu time in the current process */
#define CLOCKTYPE  CLOCK_PROCESS_CPUTIME_ID
#else
/* this one should be appropriate to avoid errors on multiprocessors systems */
#define CLOCKTYPE  CLOCK_MONOTONIC
#endif
 
double time_it(int (*action)(int), int arg)
{
  struct timespec tsi, tsf;
 
  clock_gettime(CLOCKTYPE, &tsi);
  action(arg);
  clock_gettime(CLOCKTYPE, &tsf);
 
  double elaps_s = difftime(tsf.tv_sec, tsi.tv_sec);
  long elaps_ns = tsf.tv_nsec - tsi.tv_nsec;
  return elaps_s + ((double)elaps_ns) / 1.0e9;
}
 
int main()
{
  printf("identity (4) takes %lf s\n", time_it(identity, 4));
  printf("sum      (4) takes %lf s\n", time_it(sum, 4));
  return 0;
}