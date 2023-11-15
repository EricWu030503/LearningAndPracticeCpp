#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> input;
    for (int i = 0; i < 10; i++) {
        input.push_back(i);
    }
    vector<int>::iterator itr;
    for (itr = input.begin(); itr != input.end(); itr++) {
        cout << *itr << endl;
    } 
}