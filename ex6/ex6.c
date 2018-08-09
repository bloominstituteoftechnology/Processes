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
#include <string.h>
#include <stdint.h>

#define number_iter 1000000
#define BILLION 1000000000L



int main(void)
{
long sum = 0;
double average;
struct timespec start, end;

    for(int i = 0; i < number_iter; i++){

        clock_gettime(CLOCK_MONOTONIC, &start);
        //do stuff
        FILE *fp;
            // char data[140];
            fp = fopen("text.txt", "r+");
            if (fp == NULL){
                return 1;
            }
            char *fileStr1 = "";
            fwrite(fileStr1, 1, strlen(fileStr1), fp);
            fclose(fp);
        //end do stuff
        clock_gettime(CLOCK_MONOTONIC, &end);
        float diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
        sum += diff;

    }

    average = sum/number_iter;
    printf("average elapsed time = %lf nanoseconds\n", average);
    return 0;
}
