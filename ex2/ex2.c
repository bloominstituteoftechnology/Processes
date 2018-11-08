// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
  #include <sys/types.h>
  #include <sys/wait.h>
int printStr (FILE *x){
    while(1) {
      int c = fgetc(x);
      if( feof(x) ) { 
         break ;
      }
      printf("%c", c);
   }
      printf("\n");
    return 0;
}
int main(void)
{
    // Your code here 
    FILE *test = fopen("text.txt","a+");
    printf("Intial read:");
    printStr(test);
    fclose(test);

    int child = fork();
    if (child == 0){
        FILE *test = fopen("text.txt","a+");
        fprintf(test, "%s %s %s \n", "Child", "was", "here");

        printf("Child read:\n");
        fseek(test,0,SEEK_SET);


    }
    else{
        int wc = wait( NULL);
        FILE *test = fopen("text.txt","a+");
        fprintf(test, "%s %s %s \n\n", "Parent", "was", "here");

        printf("Parent read:\n");
        fseek(test,0,SEEK_SET);

    }
    printStr(test);
    fclose(test);
    return 0;
}
