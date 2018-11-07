// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *pFile;
    pFile = fopen("test.txt", "a+");

    if (pFile != NULL)
    {
        int f = fork();
        if (f > 0) 
        {
            char *pText = "I am the parent file and printed Parent text. Go to your room!"; // why are these in brackets?  cause aren't strings arrays of chars?
            // I think you go char c[amillion] = "Here we go we are cool"; <- this works, but try this -> char *varname = "Whatever"; so how we already have it R: yep because i've been editing them lol
            // they are, but you don't use bracket syntax o well idk how to string again holdup lol R: yeah strings are weird in C objects of letters is a way but that would take 10 years even with my blazing fast typing skills
            fprintf(f, "Some text: %s\n", pText);
        }
        fclose(pFile);
        else if (f == 0) 
        {
            char *cText = "I am the child file and printed child text. YeetSw4gxxx69er is my pronoun"; //how do you like my child text lol YEET
            // you cant see it but i'm dabbin like crazy in a mad attempt to be "hip" and young lol dabbing like arm gesture or dabbing like 420 blz it - that kind of dab is going to --- me up me2
            // rofl the arm gesture. medical passed for my town stateship R: that is awesome! congrats! lmao some old dude that was showing me the voting tablet shit was saying to come in and vote and I was like like " I tried to last year with trump and hilary" he was just like that wasn't last year. i'm fkin up
            // lol it feels like last year. time is moving fast  damn right d00d but anyways more dbuggz
            // gimme a minute here. need to help vancey boy
            fprintf(f, "Some text: %s\n", cText);
        }
        else 
        {
            fprintf(f, "doubt this should work\n");
        }
    }
    else
    {
            printf("Could not open the file\n");
    }
    
    return 0;
}

