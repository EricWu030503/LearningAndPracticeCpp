#include <iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    string b=to_string(a);
    for(int i=0; i<5; i++){
        if (i==4){
            cout << b[i];
        }
        else{
            cout << b[i] <<",";
        }
    }
}