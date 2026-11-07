#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Record {
    public:
    string name;
    int number;
};

int main() {
    vector<Record> book;
    string command; Record r;
    while (cin >> command >> r.name) {
        if (command == "Add") {
            cin >> r.number;
            book.push_back(r); // insert records to the end
        }
        else {
            for (int i = 0; i < book.size(); i++) {
                if (book[i].name == r.name) { //access the records
                    
                } 
            } 
        } 
    } 
}

/*
Notice that when we push_back( ) a Record r to the vector, a copy of r is created inside 
the vector. Hence, any change in r afterwards does not affect the Record inside the 
vector.

STL guarantees that push_back() takes O(1) time on average. The operator [ ], size()
and pop_back() all take O(1) time (in the worst case). Hence, vector is very efficient for 
applications that need dynamic arrays.

Vector also supports other operations like inserting to or deleting from a certain position. 
But they take O(n) time on average.
*/