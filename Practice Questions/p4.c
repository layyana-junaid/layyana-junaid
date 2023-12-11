/*
 *Programmer: Layyana Junaid 23k-0056
 *Date: 11th December 2023
 *Description: Passing 1D Array by Pointer
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// creating a function to pass an array by pointer 
void use_array_to_pointer(float *arr1, int size_1, float *arr2, int size_2, float **resultant_array, int *result_size) {
    int i = 0; // 'i' represents the current index for *arr1
    int j = 0; // 'j' represents the current index for *arr2
    int k = 0; // 'k' represents the current index for *resultant_array

    *result_size = size_1 + size_2; // calculating the size of the merged array
    //dynamically allocating the memory for the array 
    *resultant_array = (float *)malloc(*result_size * sizeof(float)); 

    //Merging the arrays while eliminating the duplicates
    while(i < size_1 && j < size_2) {
        if(arr1[i] < arr2[j]){
           (*resultant_array)[k++] = arr1[i++];
        }
        else if(arr2[j] < arr1[i]){
            (*resultant_array)[k++] = arr2[j++];
        }
        else {
            // if both the values are equal, skip one of them to eiminate duplicates
            (*resultant_array)[k++] = arr1[i++];
            j++;
        }
    } // end of while loop 

    // copying the elements from Array number 1 if any 
    while( i < size_1){
        (*resultant_array)[k++] = arr1[i++];
    }

    //copying elements from array number 2 if any 
    while( j < size_2){
        (*resultant_array)[k++] = arr2[j++];
    }
} // end of arry to pointer function


int main(int argc, char const *argv[]) {
    float arr1[] = {-10.5,-1.8,3.5,6.3,7.2};
    float arr2[] = {-1.8,3.1,6.3};

    int size_1 = sizeof(arr1) / sizeof(arr1[0]); // calculating the size of array 
    int size_2 = sizeof(arr2) / sizeof(arr2[0]); // calculating the size of array 

    float *resultant_array;
    int result_size;

    use_array_to_pointer(arr1,size_1, arr2,size_2, &resultant_array, &result_size);
    
    // displaying the merged array 
    printf("The Merged Array looks like this: \n");
    for(int i = 0; i < result_size; i++) {
        printf("%.2f ", resultant_array[i]);
    }
    printf("\n");

    free(resultant_array);

    return 0;
} // end main 