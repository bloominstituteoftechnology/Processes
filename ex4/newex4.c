#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  printf("***** hello word ********\n");
  printf(" process id:%d \n", (int)getpid());
  int ronado = 10;
  ///////////////////////////////////////
  //===========>exec ends with V =====> victore = array:
  char *array[] = {"./ex4", "hi", "how", "are", "you", NULL};
  execvp(array[0], array); /// execvp takes start this process in the other file , array[0]=file address, and argc
  //==========>  exec ends with L  ====> for comma separated arguments:
  // execl("./ex4", "hi", "how", "are", "you", NULL);
  //==========>  exec ends with p ====> p is for path

  return (0);
}