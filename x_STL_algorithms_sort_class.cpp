#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Email {
    public:
    string sender;
    string subject;
};

bool operator <(const Email& a, const Email& b) {
    if (a.sender < b.sender) return true;
    if (a.sender > b.sender) return false;
    return a.subject.size() < b.subject.size();
}

int main() {
    vector<Email> v;
    for (int i = 0; i < 10; i++) {
        Email s;
        cin >> s.sender >> s.subject;
        v.push_back(s);
    }
    sort(v.begin(), v.end()); //Error!
    vector<Email>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++)
        cout << (*itr).sender << '\t' << (*itr).subject << endl;
}