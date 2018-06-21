// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
 FILE *fp;
 fp = fopen("text2.txt","w+");   
int rc = fork();
if(rc<0)
{
fprintf(stderr, "fork failed\n");
exit(1);
}
else if (rc ==0)
{
fprintf(fp,"%s %s %s\n %d\n","Jacob","Leon","Lyerla",2018);
}
else
{
fprintf(fp,"%s %s %s\n %d\n","Sr.","Dev","Rolt",2019);
}
    
    return 0;
}
