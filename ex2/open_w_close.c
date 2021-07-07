# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    FILE *fp ;
    char data[50];
    // opening an existing file
    printf( "Opening the file test.c in write mode" ) ;
    fp = fopen("test.c", "w") ;
    if ( fp == NULL )
    {
        printf( "Could not open file test.c" ) ;
        return 1;
    }
    printf( "\n Enter some text from keyboard” \
             “ to write in the file test.c" ) ;
    // getting input from user
    while  (strlen ( data )  > 0 )
    {
        // writing in the file
        fputs(data, fp) ;   
        fputs("\n", fp) ;
    }
    // closing the file
    printf("Closing the file test.c") ;
    fclose(fp) ;
    return 0;        
}