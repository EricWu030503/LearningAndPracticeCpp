#include <iostream>
#include <vector>
using namespace std;

void print(vector<string> v){
    cout << "Items: ";
    for (int i =0; i < v.size(); i++){
        if (i == v.size()-1)
            cout << v[i] << endl;
        else
            cout << v[i] << ", ";
    }
}

int main(){
    vector<string> v;
    cout << "Items: "<< endl;
    v.push_back("eggs");
    v.push_back("milk");
    v.push_back("sugar");
    v.push_back("chocolate");
    v.push_back("flour");
    print(v);
    v.pop_back();
    print(v);
    v.push_back("coffee");
    print(v);
    for (int i =0; i < v.size(); i++){
        if (v[i] == "sugar"){
            v[i] = "honey";
        }
    }
    print(v);
    for (int i =0; i < v.size(); i++){
        if (v[i] == "milk"){
            v.erase(v.begin()+i);
        }
    }
    print(v);
    return 0;
}