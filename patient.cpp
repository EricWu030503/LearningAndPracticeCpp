#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;



int main(){
    int n;
    cin >> n;
    double a, b, c, d;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp <= 18){
            a++;
        }
        else if (temp >= 19 && temp <= 35){
            b++;
        }
        else if (temp >35 && temp <= 60){
            c++;
        }
        else{
            d++;
        }
    }
    int sum = a + b + c + d;
    a = a / sum *100;
    b = b / sum *100;
    c = c / sum *100;
    d = d / sum *100;
    cout << fixed << setprecision(2);
    cout << "1-18: " << a << "%" << endl;
    cout << "19-35: " << b << "%" << endl;
    cout << "36-60: " << c << "%" << endl;
    cout << "60-: " << d << "%" << endl;
    return 0;
    

}