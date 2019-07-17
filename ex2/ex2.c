// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
	FILE *fp;
	int c;

    fp = fopen("text.txt", "r+");
    
    int rc = fork();

    if (rc < 0) {
    	printf("Fork failed...\n");
    } else if (rc == 0) {
    	fprintf(fp, "This is the child.\n");
    } else {
    	fprintf(fp, "This is the parent.\n");
    }

    while(1) {

    	c = fgetc(fp);

    	if (feof(fp)) {
    		break;
    	}
    	printf("%c", c);
    }
    printf("\n");

    fclose(fp);

    return 0;
}
