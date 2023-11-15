#include<iostream> 
#include<string>
using namespace std;

struct Product{
    string name;
    double price;
};

struct Student {
    char* name;
    char* id;
    int age;
    Student(char* nm, char* d, int a) {
        name = nm;
        id = d;
        age = a;
    } // this is a struct constructor
};

int main(){
    Product p1;
    //Product p = { "Chicken",20 }; A structure variable can be initialized in an initialization list when it is declared.
    p1.name = "Chicken"; 
    p1.price = 20;
    cout << p1.name << " cost $" << p1.price << endl; 

    p1.price *= 1.1;
    p1.name.insert(p1.name.length(), " wing");
    cout << p1.name << " cost $" << p1.price << endl;

    Product p2 = p1; //The assignment operator = works for structure variables.
    cout << p2.name << " cost $" << p2.price << endl;
    // But operators like +, -, *, /, >, <, ==, etc. won’t work for structure variables. They are not defined for structs.

    Student s1("Tim", "3035123456", 20); // initialize the variables within a struct
    Student* s2 = new Student("Tim", "3035123456", 20); // creates a new cell in the heap.  Its value is a pointer to the new cell.
}

/*
A struct is a collection of one or more variables 
grouped together under a single name.

The data elements in a structure are known as its 
member variables, which can be of different types.

Once a structure type is defined, its structure name 
can be used to declare variables of this structure type

A struct can have multiple constructors as follows:
struct Student {
    char* name;
    char* id;
    int age;
    Student(char* nm, char* d, int a) {
        name = nm;
        id = d;
        age = a;
    }
    Student(char* nm, char* d) {
        name = nm;
        id = d;
    }
    Student(char* nm) {
        name = nm;
    }
}
We call this overloading (functions having the same name but different parameter lists)
*/