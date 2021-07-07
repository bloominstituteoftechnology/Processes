#include <stdio.h>
#include <stdlib.h>

int main()
{
   char my_string[3] = {"hello", "world", "world" "/0"};//definite size of a string, null terminated(array of characters)
   char my_other_string[]="hello";  //none definite size

   printf("my string is: %s\n", my_string);
   printf("my string value is: %s\n", my_other_string);
   return 0;
}