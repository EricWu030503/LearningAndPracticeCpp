#include<string>
using namespace std;

class Product{
    public:
        Product (string n, double p);
        //This is a Constructor member function. 
        //It has NO function type, and the name MUST BE THE SAME as the class name
        Product (string n);
        //A class can have more than one constructors.
        void showProductInfo();
        void raisePrice(double percent);
    private:
        string name;
        double price;
    };

/*
Declaration of the Product class

In x_class_product.h header file, we 
define the Product class by 
specifying the member variables 
and member functions

This public keyword means the following 
member functions and member variables 
are accessible to “public”.
*/

/*
Constructors

1. Must be a public member.
2. Cannot be called explicitly using member (dot) operator
3. If no constructor is defined for a class, the compiler assumes a default constructor with no arguments.
*/