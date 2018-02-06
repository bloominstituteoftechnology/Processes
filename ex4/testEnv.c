#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
        char * sla =  getenv("LS_SWITCHES1");
       // printf("getenv(\"LS_SWITCHE1\": %s\n", sla);
        char * scolor =  getenv("LS_SWITCHES2");
       //  printf("getenv(\"LS_SWITCHES2\": %s\n", scolor);
        char * shulo =  getenv("LS_SWITCHES3");
       // printf("getenv(\"LS_SWITCHES3\": %s\n", shulo);        
        char * slscolor =   getenv("LS_SWITCHES4");
       // printf("getenv(\"LS_SWITCHES4\": %s\n", slscolor);
        setenv("LS_COLORS", slscolor, 1);
        // char * testLS = getenv("LS_COLORS");
        // printf("setenv worked %s", strcmp(testLS, slscolor) == 0 ? "True" : "False");

        // char color[1024];
        // sprintf(color,"LS_COLORS=%s", slscolor );
        // char const * env[] = { color };
        char *myargs[] = {   // allocate an array of chars to hold 3 bytes
        "ls",    // pass the name of the program we want to run as the first array element 
        sla,    // argument: the ls switches
        shulo,
        scolor,
        NULL};  
        printf("myargs: %s %s %s %s\n", myargs[0],myargs[1],myargs[2],myargs[3]);
        execvp(myargs[0], myargs);  
}