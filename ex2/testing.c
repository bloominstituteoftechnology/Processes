#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  FILE *fp;
  int i, j;
  pid_t pid;

  pid = fork();

  fp = fopen("text.txt", "w");
  for(i = 2; i < 1000; i++){
    for(j=2; j<i; j++){
      if(i % j == 0){
        break;
      }
    }
    if(j==i){
      fprintf(fp, "Prime: %d\n", i);
    }
  }

  if(pid == 0)
  {
    fprintf(fp, "The child added this...\n");
  }else if(pid > 0)
  {
    fprintf(fp, "The parent added this...\n");
  }
  fclose(fp);

  return 0;
}
