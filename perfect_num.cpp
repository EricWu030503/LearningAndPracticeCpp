/*
   This program prints out the perfect numbers between 1 and N
*/

#include <iostream>
using namespace std;

const int N = 1000;

bool isPerfect(int num){
    int sum = 1;
    for(int i = 2; i<num; i++){
        if (num%i == 0){
            sum +=i;
        }
    }
    if (sum == num) return true; else return false;
}

int main()
{
	cout << "For the integers from 1 to " << N << ":\n";

	for (int j = 2; j <= N; ++j)
		if (isPerfect(j))
			cout << j << " is perfect\n";

	cout << endl;

	return 0;
}