
// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable 
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? 
// What happens to the variable when both the child and parent change the value of x?
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <unistd.h> //:(){ :|: & };: 
 
 int main(int argc, char *argv[]) { 
     // Your code here 
     int s = 100; 
     int rc = fork(); 
     if(rc < 0) { 
         fprintf(stderr, "The fork was not successful \n"); //This sends formatted output to a stream exit(1); 
         } 
         else if(rc == 0) { 
             printf("The fork was a success. Incremented child value is now %d\n", ++s); 
             } 
             else { 
                 printf("The fork was a success. Incremented parent value is %d\n", ++s); 
                 } 
                 return 0; }