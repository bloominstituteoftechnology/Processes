// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp;
    int c;

    fp = fopen("text.txt", "w"); // open text.txt
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2018); // write a string to text.txt
    fclose(fp);

    int rc = fork();
    // --- child process starts here ---
    if (rc < 0)
    {
        fprintf(stderr, "Fork blew up! Try again \n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child result here, fp = %p\n \n", fp); // print address of the text.txt
        fp = fopen("text.txt", "r");
        while(1) {
		    	c = fgetc(fp); // get next character from fp and advances index
		    	if( feof(fp) ) { // test end of file indicator
		    		break ;
		    	}
		    	printf("%c", c);
		    }
		    printf("\n");
		    fclose(fp);
    } else {
        printf("Parent result here, fp = %p\n \n", fp);
        fp = fopen("text.txt", "r");
        while(1) {
			  	c = fgetc(fp);
			  	if( feof(fp) ) {
			  		break ;
			  	}
			  	printf("%c", c);
			  }
			  printf("\n");
			  fclose(fp);
    }

    return 0;

    // ~~~~ alt ver ~~~~
    // // fopen() text.txt
    // FILE *file;
    // file = fopen("./text.txt", "r+");

    // int c;

    // int rc = fork();
    // // Child process starts here
    // if (rc < 0)
    // {
    //     fprintf(stderr, "Fork Failed \n");
    //     exit(1);
    // }
    // else if (rc == 0)
    // { // Child process writes to text.txt
    //     char stringChild[] = "This is the child process\n";
    //     fwrite(stringChild, 1, sizeof(stringChild), file);

    //     file = fopen("./text.txt", "r+");
    //     while (1)
    //     {
    //         c = fgetc(file);
    //         if (feof(file))
    //         {
    //             break;
    //         }
    //         printf("%c", c);
    //     }
    //     fclose(file);
    // }
    // else
    // { // Parent process writes to text.txt
    //     char stringParent[] = "This is the parent process\n";
    //     fwrite(stringParent, 1, sizeof(stringParent), file);
    // }

    // return 0;
}
