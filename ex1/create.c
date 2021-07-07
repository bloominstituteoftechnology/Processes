#include <stdlib.h>
#include <stdio.h>

int main(){
  FILE * fpointer= fopen("employees.txt","w");

  fprintf(fpointer, "Kiki, PM\nJoe, M" );
    

  fclose(fpointer);
  return 0;
}