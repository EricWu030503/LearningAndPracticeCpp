#include <iostream>
using namespace std;

// ### Implement birthday() here ###
void birthday(int &age){
    age++;
}
// ###

int main(){
    int myAge;
    cin >> myAge;
    birthday(myAge);
    cout << "My age after birthday is " << myAge;
}