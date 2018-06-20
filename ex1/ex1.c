// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
 int q = 10;
 printf("hi (pid: %d)\n", q);
 int rc = fork();
 if(rc < 0) {
     fprintf(stderr, "fork failed\n");
        exit(1);
 }
 else if(rc == 0){
     q++;
     printf("Child thing (pid: %d) \n", q);
 } else {
     
      printf("Parental Unit 1 (pid: %d) \n", q);
      q--;
      printf("Parental Unit 2 (pid: %d) \n", q);
 }

    return 0;
}
