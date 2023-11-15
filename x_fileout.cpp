#include<fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    ofstream file;
    /*
    When opening a file for output using the member 
    function open(), a new file will be created if the file 
    does not already exist, otherwise the content of the 
    existing file will be erased.

    To keep the content of the existing file and append 
    new data to it, supply the constant value ios::app 
    as the second argument to the member function 
    open().
    */
    //file.open("receipt.txt", ios::app);
    file.open("receipt.txt");
    if (file.fail()){
        cout << "Fail to open the file" << endl;
    }
    else{
        double amount;
        double tax;
        cin >> amount;
        cin >> tax;
        file << "Welcome to Wing’s supermarket" << endl;
        file << "----------------------------------------" << endl;
        file << "Purchase amount $" << amount << endl;
        file << "Tax (tax rate is 5%) $" << tax << endl;
        file << "----------------------------------------" << endl;
        file << "Total $" << (amount + tax ) << endl;
        file << "Thank you!" << endl << endl;
        if ( amount >= 200){
            file << " ---------------Coupon--------------" << endl;
            file << " 10% off for the next purchase." << endl;
            file << "----------------------------------------" << endl; 
        }
        file.close();
        }
    return 0;
}