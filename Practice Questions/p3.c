/*
 *Date: 10th December 2023
 *Description: Recursively implement a function that finds the length of a string 
 *Programmer: Layyana Junaid 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLength(char *str) {
  if(*str == '\0') {
    return 0;
  }
    // recursive case = add 1 to the length and move to the next character
    return 1 + stringLength(str + 1);
} // end stringLength

int main(int argc, char const *argv[])
{
    char *string = "Layyana Junaid"; // note that space is also a character 
    int length = stringLength(string);

    printf("Length of the string is %d\n", length);

    return 0;
} // end main 
