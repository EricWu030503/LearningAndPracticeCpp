#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    vector<string> input;
    for (int i = 0; i < 5; i++) {
        string s; 
        cin >> s;
        input.push_back(s);
    }
    sort(input.begin(), input.end()); // void sort(RandomAccessIterator first, RandomAccessIterator last);
    // It sorts the items in the range [first, last) into ascending order.
    vector<string>::iterator itr;
    for (itr = input.begin(); itr != input.end(); itr++){
        cout << *itr << endl;
    }
    // sort an array
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = i * 3 % 10;
    }
    sort(a, a + 10);
    for (int i = 0; i < 10; i++) {
        cout << input[i] << ' '; 
    }
    /*
    Note that STL would convert an integer pointer into a random access iterator. Note that the 
    array name input is a constant pointer pointing to the first item and input+10 points to 
    input[10], which is one position after the last item. Hence all items in input are sorted.
    */
}

/*
We cannot sort a list or a map using their iterators, because those containers provide only 
bidirectional iterators instead of random access iterators.

sort() takes O(n log n) time on average, where n is the number of items in the range.
*/