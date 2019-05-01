// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?


//https://stackoverflow.com/questions/4204915/please-explain-the-exec-function-and-its-family
//https://linux.die.net/man/3/execl
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here   
    int ex4 = fork();

    if(ex4 < 0){
        printf("fork failed!");
        exit(1);
    } else if (ex4 == 0){
        printf("child fork\n");
        execl("/bin/ls", "/bin/ls", NULL); //returns folder and file names

        perror("exec");
        exit(1);

    } else {
        wait(NULL);
        printf("parent fork\n");
        execl("/bin/ls", "/bin/ls", NULL);
    }

    return 0;
}

//exec()
//execl() - returns folder and file name
//execlv()
//execv()