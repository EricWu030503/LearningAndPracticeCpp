#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a = 1.2345678;
    double b = 1234567.8;
    cout << a << '\n' << b << "\n\n";
    cout << setprecision(2);
    cout << a << '\n' << b << '\n';
    return 0;
}
/*
With the default floating-point notation, setprecision
specifies the maximum number of meaningful digits before 
and after the decimal point
*/