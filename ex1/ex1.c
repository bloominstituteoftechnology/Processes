// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
//set main process value to 100
int x = 100;
printf("This is a parent program (pid: %d)\n", (int) getpid());
int rc = fork();
if (rc < 0) {
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
printf("This is a child (pid: %d) and x is: %d\n", (int) getpid(), x);
x++;
printf("This is still a child and x is now: %d\n", x);
} else {
printf("The parent of  %d (pid: %d) where x is: %d\n", rc, (int) getpid(), x);
x--;
printf("This is still the parent, x is now: %d\n", x);
}
return 0;
}
