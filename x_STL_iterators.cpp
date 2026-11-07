#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;



int main(){
    // Declare an iterator
    vector<string>::iterator itr;
    // Indexing items in a container
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5); // v = [3, 4, 5] now
    vector<int>::iterator itrOfV = v.begin(); // Given a container c, then c.begin() returns an iterator pointing to the first item in c.
    *itrOfV = 100; // change value 3 to 100
    cout << *itrOfV << endl; //print 100
    // Moving the iterator
    vector<int>::iterator itr = v.begin();
    for (int i = 0; i < v.size(); i++) {
        cout << *itr << ' ';
        itr++; 
    }// print 100 4 5
    // Testing the end of the container
    vector<int>::iterator itr2;
    for (itr2 = v.begin(); itr2 != v.end(); itr2++) {
        cout << *itr2 << ' '; 
    }
    return 0;
}
/*
Forward iterator:
    Assignment: a = b;
    Increment: a++;
    Dereference: *a;
    Equality test: a == b;

Bidirectional iterator:
    Assignment: a = b;
    Increment: a++;
    Dereference: *a;
    Equality test: a == b;
    Decrement: a--;

Random access iterator:
    Assignment: a = b;
    Increment: a++;
    Dereference: *a;
    Equality test: a == b;
    Decrement: a--;
    Arithmetic +/-: a+5; a-5; a-b;
    Inequality test: a<b; a>b; a<=b; a>=b;
    Compound: a+=5; a-=5;
    Offset dereference: a[5]; //i.e., *(a+5)

All iterator operations specified above take only O(1) time.

The type of an iterator is determined by the container which the iterator is pointing to. 
Iterators to vectors are random access iterators. Iterators to list or map are bidirectional 
iterators.
*/