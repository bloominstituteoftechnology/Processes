// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;
    int i, j;
    pid_t pid;

    pid = fork();

    if(pid < 0){
      printf("Fork failed.\n");
      exit(1);
    }else if(pid == 0){
      fp = fopen("text.txt", "w");
      for(i = 2; i < 100; i += 2){
        fprintf(fp, "Even: %d\n", i);
      }

      fclose(fp);
    }else{
      fp = fopen("text.txt", "w");
      for(i = 3; i < 1000; i++){
        for(j=2; j<i; j++){
          if(i % j == 0){
            break;
          }
        }
        if(j==i){
          fprintf(fp, "Prime: %d\n", i);
        }
      }
      fclose(fp);
  }

    return 0;
}
