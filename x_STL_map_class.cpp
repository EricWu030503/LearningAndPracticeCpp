#include <iostream>
#include <string>
#include <map>
using namespace std;

class Record {
public:
    string name;
    int number;
};

/*
To support efficient searching using the keys, map stores the <key,
value> pairs in ascending order of the keys. Hence, it requires the keys to have a total order
(i.e., a totally ordered set or a linearly ordered set). In particular, it requires that the less than operator < is defined for the keys.
For user-defined classes, the operator < is not defined. Hence a compilation error occurs. To 
solve the problem, add the following operator overloading before the main() function.
*/
bool operator<(const Record& a, const Record& b) {
    return a.name < b.name;
}

int main() {
    map<Record, int> book;
    string command; Record r;
    while (cin >> command >> r.name) {
        if (command == "Add") {
            cin >> r.number;
            book[r] = r.number;
        }
        else {
            cin >> r.number;
            if (book.count(r) > 0) {
                cout << book[r]; 
            }
            else { 
                cout << "Name not found" << endl; 
            }
        } 
    } 
}