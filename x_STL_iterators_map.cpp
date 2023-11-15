#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, double> input;
    for (int i = 0; i < 5; i++) {
        input[i * 3 % 5] = i + 0.1;
    }
    map<int, double>::iterator itr;
    for (itr = input.begin(); itr != input.end(); itr++) {
        cout << (*itr).first << ' ' << (*itr).second << endl;
        // (*itr).first accesses the key and (*itr).second accesses the value.
    } 
}

/*
Notice that the pairs are printed in ascending order of the key. It is expected because a map
stores the pairs in sorted order of the keys. Hence, you may use a map to sort a set of items 
indirectly.
*/