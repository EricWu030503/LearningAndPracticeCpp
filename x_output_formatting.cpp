#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double f = 0.135;
    cout.precision(6);
    cout << f << endl; 
    cout << fixed << f << endl; 
    cout << scientific << f << endl; 
    cout.unsetf(ios_base::floatfield); //remove the previous setting
    cout << f << endl;
    return 0;
}