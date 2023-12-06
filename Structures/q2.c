/*
 *Description: Write a function 'sumvector' which returns the sum of two vectors passed to it. the vectors must be 2d vectors
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Vector2D;

Vector2D sumvector( Vector2D v1, Vector2D v2 ) {
    Vector2D result; // creating a function to store the value of the sum of the two vectors
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
} // end of sumvector

int main() {
    Vector2D v1 = { 1 , 2 };
    Vector2D v2 = { 3 , 4 };
    Vector2D result = sumvector( v1 , v2 );
    printf("The sum of the two 2D vectors is (%di + %dj)\n", result.x, result.y);
    return 0; 
} // end main 
