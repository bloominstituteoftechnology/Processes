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

uint64_t getAverageTime(int method)
{
  uint64_t totalRuntime = 0;
  struct timespec start, end;

  for (int i = 0; i < number_iter; i++)
  {
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    switch (method)
    {
      case 1:
        write(STDOUT_FILENO, "", sizeof("") - 1);
        break;
    
      case 2:
        printf("");
        break;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    totalRuntime = totalRuntime + (BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
  }

  return totalRuntime / number_iter;
}

int main()
{
  
  printf("Average time to make a system call to do an empty write to stdout: %llu nanoseconds\n", (long long unsigned int)getAverageTime(1));

  // Comparing system call to stdio library function printf
  printf("Average time to call standard library function printf(): %llu nanoseconds\n", (long long unsigned int)getAverageTime(2));

  return 0;
}
