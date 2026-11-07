#include <iostream>
using namespace std;

int number_of_divisors(int n){
    int count = 0;
    for(int i =1; i<=n; i++){
        if(n%i == 0){
            count ++;
        }
    }
    return count;
}

int smallest_antiprime(int n){
    int max_divisors=0;
    for(int i = 1; i < n; i++){
        if(number_of_divisors(i)>max_divisors){
            max_divisors = number_of_divisors(i);
        }
    }
    int antiprime_divisors;
    do{
        antiprime_divisors = number_of_divisors(n);
        n++;
    }while (antiprime_divisors <= max_divisors);
    return n-1;
}

int main(){
    int num;
    cin >> num;
    cout << smallest_antiprime(num);
    return 0;
}