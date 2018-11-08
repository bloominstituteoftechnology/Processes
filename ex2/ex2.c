
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  FILE * fp;

  fp = fopen ("file.txt", "w+");
  fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);

  fclose(fp);

  return(0);
}
