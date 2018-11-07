#include<stdio.h> 
#include<unistd.h> 
  
int main(void) 
{ 
    int x = 100;
    printf("I am exec.c called by execvp()\n"); 
      
    return x; 
} 