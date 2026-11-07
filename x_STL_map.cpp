#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> book;
    string command, name; int number;
    while (cin >> command >> name) {
        if (command == "Add") {
            cin >> number;
            book[name] = number;
        }
        else {
            if (book.count(name) > 0) {
                cout << book[name]; 
            }
            else { 
                cout << "Name not found" << endl; 
                }
        } 
    } 
}

/*
The STL map is a container that supports more efficient searching(O(log n)).

map<K, V> m: This creates a map m such that each pair in m has key of type K and 
value of type V. For example, map<string,int> m create a map m 
where each pair in m has a string as the key and an int as the value.

map[key]: Given any key, the [ ] operator access the corresponding value. If no 
pair with such key exists in the map, map[key] will create a pair with 
this key and set the default value for the pair.

int count(key): Given any key, this function returns the number of pairs in the 
map with this key. Hence, it returns 1 if such key exists; it returns 0 
otherwise. It is usually used to check if a key exists before accessing 
the value through m[key].

int size(): Return the number of pairs in the map.

No two elements in the map can have same keys
*/