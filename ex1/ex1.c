// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    char str[100] = "What does fork() do\n";
    int num = 100;
    printf(str);
    printf(num)
    fork();
    str = "Because it has been forked, this sentence should print twice.\n";
     printf(str);
<<<<<<< HEAD

=======
    
>>>>>>> 3e7e81f6fcbf8b24fd7a3f83434587959289d471
    num += 100;
    printf("%d \n", num); // my guess:200 300
    return 0;
}
