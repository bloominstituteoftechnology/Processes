// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *text1 = fopen("text.txt", "w");

    char data[] = "A new string!";
    char data2[] = "A second new string!";

    

    int child = fork();

    if (child < 0) {
      printf("process failed.");
    }
    else if (child == 0) {

      fwrite(data2,1,sizeof(data2), text1);
    } else {
      fwrite(data, 1, sizeof(data), text1);
    }
fclose(text1);
return 0;
}
