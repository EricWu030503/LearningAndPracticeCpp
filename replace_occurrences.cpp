#include <iostream>

using namespace std;

int main(){
    string a,b,c;
    getline(cin,a);
    cin >> b >> c;
    int index = a.find(b);
    while (index != -1){
        a.replace(index,b.length(),c);
        index = a.find(b,index+c.length());
    }
    cout << a ;
    return 0;
}