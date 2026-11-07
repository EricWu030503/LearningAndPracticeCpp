#include <iostream>
using namespace std;

int main(){
    int a[4]={1, 2, 3, 4};
    cout << a[0] << a[1] << a[2] << a[3] << endl;
    int * p = a;
    cout << p << endl;
    cout << *p << *(p+1) << *(p+2) << *(p+3) << endl;
    cout << p[0] << p[1] << p[2] << p[3]; // p[i] is in fact the short form of *(p+i)
    return 0;
}

/*
When a pointer is referring to an array, it is storing the 
address of the 1st slot of the array.

We can use the increment / decrement operator on pointer 
variable to go to the next / previous slot of the array.
*/