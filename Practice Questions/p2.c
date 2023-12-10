/*
 *Date : 10th December 2023
 *Description : Taking two strings as an input , and adding them together, while returning there output
 *Programmer : Layyana Junaid
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// this function will reverse a string
// whats the need to reverse the string?
// it is done in order to carry out addition properly , just like we used to do in the primary schools,
// adding the last digit first and so on
void string_reverse(char *str) {
	for(int i = 0; i < strlen(str)/2; i++) {
        char temp = str[i];
        str[i] = str[strlen(str)- 1 - i];
        str[strlen(str)-1 - i] = temp;
	}
} // end reverse function

// defining string adder function where the two string will be added
void *string_adder(char *string1, char *string2) {
	bool carry = false; // initializing carry flag to (false) zero, and when a number is carried it becomes true
	// getting the length of string 1 and string 2 and find the maximum 
	int len1 = strlen(string1);
	int len2 = strlen(string2);
	int n = (len1 > len2) ? len1 : len2;

	// calloc(ing) a resultant string which has to be returned 
	char *result = (char *)calloc(sizeof(char), len1+len2);
	string_reverse(string1), string_reverse(string2); // reversing the strings
	for(int i = 0; i < n; i++) {
		int num1 , num2 = 0; // initializing both the numbers as zero 
	 // incase 'i' exceeds the length of any of the two strings
	 if (i < len1) num1 = string1[i] - '0';
	 if (i < len2) num2 = string2[i] - '0';

	 result[i] = (num1 + num2) % 10 + '0' + carry; // carry will only be added incase of true
	 if (carry) carry = false; // incase the previous carry was on (true), it will get off (false)
	 // if the sum of both the numbers was greater then 10 than turn back carry on (true)
	 if ( num1 + num2 >= 10 ) carry = true;
	} // end of for loop 

	// addition of final carry , incase there is any
	if (carry) result[strlen(result-1)]++;

	// once everything is done, reverse te string again 
	string_reverse(result);
	return result;
} // end of string_adder function

int main(int argc, char const *argv[]) {
 	
 	char num1[50] = "1213131313123545345";
 	char num2[50] = "1230814148482948234";
 	char *sum = string_adder(num2, num1);

 	// printing the sum 
 	printf("%s\n", sum);
 	return 0;
 } 