#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int n;
    FILE *fptr;
    fptr = fopen("text.txt","a+");
    
    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Welcome to the Thunder Dome!\n");
        printf("Enter number: \n");
        scanf("%d", &n);
        fprintf(fptr,"%d", n);
        fclose(fptr);
    } else {
        waitpid(rc, NULL, 0);
        printf("Enter number: \n");
        scanf("%d", &n);
        fprintf(fptr, "%d", n);
        fclose(fptr);
        printf("It's been fun :/\n");
    }
    return 0;
}
