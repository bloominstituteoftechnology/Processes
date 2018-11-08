// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("text.txt", "w");
    int rc = fork();
    char par_str[] = "This is from the parent.\n";
    char chi_str[] = "This is from the child.\n";
    
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        fprintf(fp, "%s", chi_str);
    } else {
        fprintf(fp, "%s", par_str);
    }
    
    fclose(fp);
    return 0;
}
