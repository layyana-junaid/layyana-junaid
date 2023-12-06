/*
 *Description: create a three dimensional vector using structures.
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector3D;

Vector3D create_Vector3D(int x, int y, int z) {
    Vector3D newVector;
    newVector.x = x;
    newVector.y = y;
    newVector.z = z;
    return newVector;
}

void printVector3D(Vector3D v) {
    printf("(%d, %d, %d)\n", v.x, v.y, v.z);
}

int main() {
    Vector3D v1 = create_Vector3D(31, 5, 04);
    Vector3D v2 = create_Vector3D(24, 7, 04);
    Vector3D v3 = create_Vector3D(28, 6, 23);
    printVector3D(v1);
    printVector3D(v2);
    printVector3D(v3);
    return 0;
}
