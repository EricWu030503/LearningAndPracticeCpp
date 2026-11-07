#include <iostream>
#include <string>
using namespace std;



int main(){
    int size;
    cin >> size;
    int *a = new int[size];
    for (int i = 0; i < size; i++){
        cin >> a[i];
    }
     for (int i = 0; i < size - 1; i++) {
      for (int j = 1; j < size - i; j++) {      
        if (a[j - 1] > a[j]) {
          int temp = a[j];
          a[j] = a[j - 1];
          a[j - 1] = temp;
        }    
      }  
    }
    int max = 1;
    int temp = 1;
    int mode = a[0];
    for (int i = 0; i < size; i++){
        if (a[i] == a[i+1]){
            temp ++;
        }
        else{
            if (temp > max){
                max = temp;
                mode = a[i];
            }
            temp = 1;
        }
    }
    cout << "The mode of the set is " << mode;
    delete[] a;
    return 0;
}
