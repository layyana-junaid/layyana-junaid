/*
 *Programmer: Layyanan Junaid 
 *Date: 15th Feb 2024
 *Topic : Concept of Constructors ( Parameterized Constructor, Copy Constructor, Default Constructor)
 *
 */


 #include <iostream>
 #include <string>

 using namespace std;

 class Student {
    public:
    string name;
    int rollNum;


    Student() {
        cout << "Constructor" << endl;
    }

    ~Student() {
        cout << "Destructor" << endl;
    }
 };

 int main(int argc, char const *argv[])
 {
    Student s1; // object
    Student s2; // object
    s1.name = "Layyana";
    s2.name = "Alisha";
    cout << s1.name << endl;
    cout << s2.name << endl;
    return 0;
 }
 