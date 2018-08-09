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
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define number_iter 1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    int arr[number_iter];
    int counter = 0;
    while (counter < number_iter) {
        clock_t t;
        t = clock();
        printf("");
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        double nanosecond = time_taken * BILLION;
        arr[counter] = nanosecond;
        counter++;
    }
    double sum = 0;
    for (int i = 0; i < number_iter; i++) {
        sum += arr[i];
    }
    double average = sum / number_iter;
    printf("%f\n", average);
    return 0;
}
