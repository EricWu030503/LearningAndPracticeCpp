#include <iostream>
using namespace std;

struct Product{
    string name;
    double price;
};

void search (Product *ProductList, string searchName){
    for ( int i = 0 ; i < 4 ; i++ ){
        if ( ProductList[i].name == searchName ){
            cout << ProductList[i].price << endl; 
        }
    }
}

void delete_product (Product *ProductList, int slotID, int size){
    for (int i = slotID ; i < size-1 ; i++){
        ProductList[i] = ProductList[i+1]; 
    } 
}

int main(){
    Product *ProductList;
    ProductList = new Product[4];  // Reserves 4x2 = 8 cells from the free store for storing Products. Then, it will return the address of the first slot.
    ProductList[0].name = "chicken";
    cout << ProductList[0].name;
    // insertion
    int size = 4;
    Product *temp; 
    temp = new Product[size]; // Create a temporary array with the same size as the old array
    for (int i =0 ; i < size ; i++){ 
        temp[i] = ProductList[i]; // Copy elements from the old array to the temporary array
    }
    delete [] ProductList; // Delete the old array
    ProductList = new Product [size+1]; // Create a new array with old array’s name and with size (size of old array + 1)
    for (int i =0 ; i < size ; i++){ 
        ProductList[i] = temp[i]; // Copy elements from the temporary array to the new array
    }
    delete [] temp; // Delete the temporary array
    ProductList[size].name = "Candy"; // Add the new element
    ProductList[size].price = 2.5;
    size++;
    return 0;
}

/*
When we create a dynamic array with big size such as:
Student * S = new Student[10000];
there can be a case that the main memory cannot 
allocate enough space to fulfill our need. Under 
normal situation, the program will throw an 
exception (error).
However, if you create the same array as follows:
Student * S = new (nothrow) Student[10000];
the program will not throw exception but just assign 
NULL to S.

Weaknesses of using array to store the list of 
items:
1. Need to initialize the initial number of array slots.

2. Deletion of an item need to move a lot of other items 
(those items after the slot that contains the entry to 
be deleted).
*/