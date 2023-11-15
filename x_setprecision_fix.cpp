#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double a = 1.2345678;
    double b = 1234567.8;
    cout << fixed << setprecision(2);
    cout << a << '\n' << b << "\n\n";
    cout << setprecision(8);
    cout << a << '\n' << b << '\n';
    return 0;
}
/*
With the fixed or scientific notation, setprecision
specifies the exact number of digits after the decimal 
point.
*/