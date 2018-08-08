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
  fp = fopen("text.txt", "w");
// this was really helpful with this: https://www.tutorialspoint.com/c_standard_library/c_function_fclose.htm
 
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failure alert\n");
    exit(1);
  }
// I used this for the fwrite part: https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
  else if (rc == 1)
  {
    char str1[] = "child";
    fwrite(str1, 1, sizeof(str1), fp);
  }
  else
  {
    char str2[] = "parent";
    fwrite(str2, 1, sizeof(str2), fp);
  } 
  fclose(fp);
  
  return 0;
}

// after running this nothing appeared to happen so I checked the text.txt file that I was writing to and it contained "parent@parent". I erased it and put my own text in there and then ran it again. It again contained "parent@parent".
