#include <iostream>
using namespace std;
int main(){
    double a;
    double sum;
    int count=-1;
    do{
        cin >> a;
        sum+=a;
        count++;
    }while(a!=-1);
    sum+=1;
    cout << sum/count;
}