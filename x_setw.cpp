#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int x = 12; 
    string a = "Hello";
    double b = 34.567;
    cout << fixed << setprecision(2);
    cout << "12345678901234567890\n";
    cout << setw(5) << x << setw(8) << a;
    cout << setw(6) << b << endl;

    cout << setfill('*');
    cout << setw(5) << x << setw(8) << a;
    cout << setw(6) << b << endl;

    cout << left;
    cout << setw(5) << x << setw(8) << a;
    cout << setw(6) << b << endl;
    return 0;
}
/*
Use setw to output a string or a number in a specific 
number of columns (the output is right-justified).
Namely, the output string or number will occupy specified number
of columns.

With setw, if the specified number of columns > the 
required number of columns, the unused columns are 
filled with spaces. We may use setfill to fill the unused 
columns with other characters.

With setw, the default output is right-justified within a column. 
Use the left manipulators to set the output to be left-justified
*/