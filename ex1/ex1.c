// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable

// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? remains 100

// What happens to the variable when both the child and parent change the value of x?  it's changed in two instances since the fork makes it so the process is pretty much working side by side
// Pull request

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int f = fork(); // missing type declaration here
    if (f > 0) {
        printf("I'm the parent (pid: %d) of child %d\n", (int) getpid(), f);
        x = 24;
        printf("%d\n", x);
    }
    else if (f == 0) {
        printf("I'm the child (pid: %d) \n", (int) getpid());
         x = 19;
         printf("%d\n", x);
    }
    else {
        fprintf(stderr, "fork failed\n"); // <-- fprintf...? idk that's what training kit said I thought it was a special one for errs
        //it was probably a typo on their behalf if you haven't heard of it not training kit but readme anywayz
        
        // ahh ok. lemme checkie. it exists, but i'm not sure if you need to import anything
        // yeah it's legit. dunno why it's not workin though
        // it's working I think R: ah i see it. nice. Is this all I was supposed to do for this one? and answer those top questions?
        // R: Yessir
        /*
        J:should it be a this format so when nando loooks in my code he doesn't think you are saying fk'd up shit he knows it's me.
        R: rofl it wouldn't surprise him. gimme a sec btw
        J:it asks what happens to the variable when both the child and parent change the value of x. It seems like it's changed in two instances since the fork makes it so the process is pretty much working side by side
        R: I think that's right. Go ahead and write that as your answer and keep on goin'
        R: I'll be working on this repo too after I finish this PR comment
        */
        printf("%d\n", x);
    }
    printf("%d\n", x);
    return 0;
}

//Here is what the readme showed:

// if (rc < 0) {    // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {    // child process satisfies this branch
//         printf("hello, child here (pid: %d) \n", (int) getpid());
//     } else {
//         printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
//     }

//     return 0;
// }

/*
## What You'll be Doing for this Lab
This was your first introduction to making system calls to an operating system kernel. Obviously, there are many more system calls that we'll talk about in a future lesson, but for now we'll just practice with these. Once you've cloned this repo, go into each directory, open up the exercise file, read the prompt, and write some C code! Compile your code with `gcc [NAME OF FILE].c -o [NAME OF EXECUTABLE]`, then run the executable with `./[NAME OF EXECUTABLE]`.

So write code, compile and run. I notice the prompt wants you to change things around and observe the differences, so make changes, then compile and run again.
gcc [NAME OF FILE].c -o [NAME OF EXECUTABLE] what is the name of the exe
we are in ex1 my bad
ah -o not -0
Do you ever get pissed that I don't read the readme enough? 
hahaha don't worry about it. i hardly read the readme too, but every time i get super stuck, it's usually
because i didn't read it.
*/