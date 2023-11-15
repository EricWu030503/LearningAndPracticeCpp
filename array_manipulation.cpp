#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int i;
    cin >> i;
    int arr[15];
    for (int z = 0 ; z < 15 ; z++){
        arr[z] = 0;
    }
    if (i<15){
        for (int j = 0 ; j < i ; j++){
        arr[j] = j*j ;
        }
        if (i < 10){
            for (int x = i+5; x < 15; x++){
                arr[x] = pow(3,x);
            }
        }

    }
    else{
        for (int j = 0 ; j < 15 ; j++){
        arr[j] = j*j ;
    }
    }
    for (int k = 0 ; k < 15 ; k++){
        cout << arr[k] << " ";
    }
    return 0;
}