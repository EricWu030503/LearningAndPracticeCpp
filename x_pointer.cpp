#include <iostream>
using namespace std;

struct Student{ 
    string UID; 
    double assignment; 
};

int main(){
    Student s = {"3035835002", 90}; // computer will allocate two memory cells for this structure variable s
    Student *student_addr = &s; // this pointer variable will only store the address of the first memory cell in Student structure variable
    cout << (*student_addr).UID << endl;
    (* student_addr ).assignment = 100;
    cout << s.assignment << endl;
    student_addr -> assignment = 90; // -> is the member access operator; student_addr -> assignment is equivalent to (* student_addr ).assignment
    cout << s.assignment << endl;
    string *p = NULL; // You can initialize pointer variables as NULL (stores no address value).
    return 0; 
}