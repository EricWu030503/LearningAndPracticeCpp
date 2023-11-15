#include "x_class_product.h"
using namespace std;

int main(){
     Product p1( "Chicken" , 20); 
     //A constructor in a class is a special type of member function, which is called at the creation of an object.
     //It is often used to initialize the member variables.
     Product p2( "Chicken" );
     //The complier will call the right constructor according to the input parameters.
     p1.showProductInfo(); 
     p1.raisePrice(10);
     p1.showProductInfo();
     // p1.price = 10; This line will cause compilation error because memeber variable price is private
     return 0; 
}

/*
A class is an expanded concept of a structure.

It consists of both member variables and member functgions 
that operate on its member variables.

An object is an instance of a class

In terms of data types and variables, a class would be the 
type, and an object would be the variable.

We can always put everything (such as the main functions, 
class declarations, member functions, …etc) in one single 
source file.

However, a better organization is to separate the class 
declarations and the member functions into different files.

In x_class_main.cpp, we only need to include 
the header file of the Product class
(i.e., x_class_product.h) so that we can use 
the Product class in this program.
(Just like using other libraries)
*/

/*
Why do we need constructors?

Recall that if Product is a struct, we can initialize p1 
using “Product p1 = {“Chicken”, 20};”

This notation no long works if Product is a class 
because Product class has member functions in 
addition of member variables and we want to 
initialize member variables only. Therefore, we need 
to make us of constructors to do the job.
*/

/*
Public vs. Private

The keyword public indicates that the members of the 
class are publicly accessible from anywhere within the 
scope of the object.

The keyword private indicates that the members of the 
class are only accessible from within other members of 
the same class.
*/

/*
Why private?

I don’t want the users of the my
Product class to be able to alter the 
variables name and price directly! 
These variable are used internally 
by the object! The use of private member 
variables avoids illegal access or change 
of the variables from outside the class.

Good programming practice: make all member 
variables private and access or change them using 
public member functions.
*/