#include <iostream>
using namespace std;

int reverse(int N) {
    N *= -1;
    int n = 0;
    while (N != 0){
        n = n*10+N%10;
        N /= 10;
    }
    return n;
}
int main() {
    int N;
    cin >> N;
    cout << reverse(N) << endl;
    return 0;
}