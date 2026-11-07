#include <iostream>
#include <string>
#include <list>
using namespace std;

class Record {
    public:
        string name;
        int number;
};

int main() {
    list<Record> book; //create a list of Records
    string command; 
    Record r;
    while (cin >> command >> r.name) {
        if (command == "Add") {
            cin >> r.number;
            book.push_back(r);
        }
        else {
            for (int i = 0; i < book.size(); i++) {
                if (book.front().name == r.name) {
                    cout << book.front().number;
                    break; 
                }
                else {
                    book.push_back(book.front());
                    book.pop_front();
                } 
            } 
        } 
    } 
}

/*
STL guarantees that the first 7 operations above takes O(1) time. Hence, it is very efficient to 
access the first and the last item. However, the operator [ ] is missing. Hence, accessing the 
ith item is quite inefficient. It takes O(i) time by traversing from the first item until the ith
item.
*/