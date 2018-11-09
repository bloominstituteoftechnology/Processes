// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int rc = fork();
    // figuring out the if/else structure?
    if ( rc < 0 ) {
        fprintf(stderr, "fork failed\n");
        exit(1);

    }else if ( rc == 0 ){
        printf("Child operation: (rc:%d) \n", rc); // print???
        printf("Child:\tX before:\t%d \n", x);
        x++;
        printf("Child:\tX after:\t%d \n", x);
    }else {
        printf("Parent operation: (rc:%d) \n", rc);
        printf("Parent:\tX before:\t%d \n", x);
        x--;
        printf("Parent:\tX after:\t%d \n", x);
    }
    return 0;
}

/*
%s  string
%d  digit
%c  character

## What You'll be Doing for this Lab
This was your first introduction to making system calls to an operating system kernel. Obviously, 
there are many more system calls that we'll talk about in a future lesson, but for now we'll just 
practice with these. Once you've cloned this repo, go into each directory, open up the exercise file, 
read the prompt, and write some C code! 
Compile your code with `gcc [NAME OF FILE].c -o [NAME OF EXECUTABLE]`, then run the executable with 
`./[NAME OF EXECUTABLE]`.

*/