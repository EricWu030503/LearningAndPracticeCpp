#include <iostream>
using namespace std;

void swap (int * x, int * y){
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}
int main(){
    int a = 2, b = 5;
    swap (&a, &b);
    cout << a << " " << b;
    return 0; 
}

/*
We can use pointers as function 
parameters, the effect is like pass by 
reference. (i.e., the swap works!)
*/
