/*
 *Programmer: Layyana Junaid 
 *Date: 9th February 2024
 *Description: Lab 3: Concepts of objects and classes 
 */


//Procedural Programming Code 

#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int num;

    cout << "Enter any positive number: ";
    cin >> num;

    int fact = factorial(num);

    cout << "Factorial of " << num << " is " << fact;
    
    return 0;
    
} // end main 