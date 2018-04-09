// Write an additional program that creates 
// two processes P1 and P2. P1 should accept 
// a string from standard input and passes it 
// to P2. P2 should concatenate the received string 
// with another string and sends it back to P1 for printing.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int p1[2];
    int p2[2];

    char p1_str[] = "ofwarcraft.com"; // store parent string
    char p2_str[100]; // input string
    pid_t p;

    if (pipe(p1) == -1)
    {
        fprintf(stderr, "pipe burst");
        return 1;
    }
    if (pipe(p2) == -1)
    {
        fprintf(stderr, "pipe burst");
        return 1;
    }
    printf("Input p2 String:\n"); // input for p2 string
    scanf("%s", p2_str); // store string
    p = fork(); // fork it all

    if (p < 0)
    {
        fprintf(stderr, "pipe burst");
        return 1;
    } else if (p > 0)
    {
        char concat_str[100];
 
        close(p1[0]); // end reading the pipe
        // write input string
        // close input string
        write(p1[1], p2_str, strlen(p2_str)+1);
        close(p1[1]);
        // wait for it
        wait(NULL);
        // now close it
        close(p2[1]); 
        // read the p2 string then run concatenate
        read(p2[0], concat_str, 100);
        printf("String is Concatenated to %s\n", concat_str);
        close(p2[0]);
    } else
    {
        close(p1[1]);

        char concat_str[100];
        read(p1[0], concat_str, 100);
        int a = strlen(concat_str);
        int i;
        for (i = 0; i < strlen(p1_str); i++)
        concat_str[a++] = p1_str[i];

        concat_str[a] = '\0';

        close(p1[0]);
        close(p2[0]);
        // write the concatenated string and close p2
        write(p2[1], concat_str, strlen(concat_str) + 1);
        close(p2[1]);

        exit(0);
    }
}