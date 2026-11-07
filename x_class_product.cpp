#include<iostream> 
#include<string>
#include "x_class_product.h"
using namespace std;

Product :: Product( string n, double p){
    name = n;
    price = p; 
}

Product :: Product( string n ){
    name = n;
}
/*
Overloading: More than one function have the 
same name but different parameter lists.
*/

void Product :: showProductInfo (){
    cout << name << " cost $" << price << endl; 
}

void Product :: raisePrice (double percent){
    price = price + ( price * ( percent /100 ));
}

/*
We write member functions of the Product class
in this x_class_product.cpp

We need to include the header 
file x_class_product.h, which contains 
the declarations of the Product
class. It is because the complier need to 
know the class declaration 
when processing x_class-product.cpp.

We need to use the 
scope operator “::” to 
tell the complier that a 
function is a member 
function specific to a 
class.
*/