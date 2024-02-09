/*
 *Programmer: Layyana Junaid 
 *Date: 9th Feb 2024
 *Description: Converting the procedural code in oop
 */

#include <iostream>
using namespace std;

class Factorial 
{

public:
    int calculate(int n) {
	  int result = 1;
      for(int i = 1; i <= n; i++) {
        result *= i;
    }
     return result;

    }
};

int main(int argc, char const *argv[])
{
	int num;

	cout << "Enter a positive integer: ";
	cin >> num;

	Factorial cal;

	int fact = cal.calculate(num);

	cout << "Factorial of " << num << " is " << fact;
    
	return 0;
}