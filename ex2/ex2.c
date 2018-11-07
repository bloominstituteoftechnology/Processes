// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor returned by `fopen()`?
    // It appears they can, as they are returning the same handle of "3" from both the Parent and the Child processes. 
// What happens when they are written to the file concurrently? 
    // It prints twice to the file. Seems too easy of an answer though, and I remain suspicious of my understanding. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * file;
    file = fopen("./text.txt", "w");

    char forked = fork();

    printf("Main File Descriptor Access: %d\n", (int) fileno(file));

    if (forked == 0) {
      printf("Child File Descriptor Access: %d\n", (int) fileno(file));

      if(file == NULL)
      {
      printf("Error opening file!\n");
      exit(1);
      }

      const char *text = "Write this to the file";
      fprintf(file, "Some text: %s\n", text);

      fclose(file);
    } else {
        printf("Parent File Descriptor Access: %d\n", (int) fileno(file));

        if(file == NULL)
        {
        printf("Error opening file!\n");
       exit(1);
       }

        const char *text = "Write this to the file";
        fprintf(file, "Some text: %s\n", text);

        fclose(file);
    }

    
    return 0;
}
