// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
FILE* fp;
fp = fopen("text.txt", "w");
int rc = fork();
if (rc < 0) {
fprintf(stderr, "fork failed\n");
exit(1);
} else if (rc == 0) {
printf("This is the child\n");
char child_string[] = "This is the child string!\n";
fputs(child_string, fp);
} else {
printf("This is the parent\n");
char parent_string[] = "This is the parent string!\n";
fputs(parent_string,  fp);
}
fclose(fp);
    return 0;
}
