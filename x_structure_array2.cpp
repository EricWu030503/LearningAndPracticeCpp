#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Product{
    string name;
    double price;
};

const int MAX = 100; 
Product catalogue[MAX];
int numberOfProduct;

void initialize_products(){
    ifstream fin;
    fin.open( "product_list.txt" );
    if ( fin.fail() ){
        cout << "Error in opening the file !" << endl;
        exit(0); // Exit the program instantly
    }
    else{
        int i = 0;
        while ( fin >> catalogue[i].name ){
            fin >> catalogue[i].price; 
            i++;
        }
        numberOfProduct = i; 
        }
    fin.close();
}

void show_menu(){
    int i;
    cout << "----------- Menu -----------" << endl;
    for (i = 0 ; i < numberOfProduct ; i++){
        cout << i << " " << catalogue[i].name;
        cout << " $" << catalogue[i].price << endl;
    }
    cout << "----------------------------" << endl; 
}
double purchase(){
    show_menu();
    int product_code;
    cout << "Please enter the code of the product : "; 
    cin >> product_code;
    int quantity;
    cout << "Please enter the quantity you want to purchase : "; 
    cin >> quantity; 
    double subtotal = catalogue[product_code].price * quantity;
    cout << "Added $" << subtotal << endl; 
    return subtotal; 
}

