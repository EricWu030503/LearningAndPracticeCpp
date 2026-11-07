#include <iostream>
#include <string>
#include <list>
using namespace std;

class Student{
    public:
        string name;
        string major;
        string id;
};
int main(){
    list<Student> database;
    string command;
    cin >> command;
    while (command != "Quit"){
        Student student;
        if (command == "Add"){
            cin >> student.name;
            cin >> student.major;
            cin >> student.id;
            database.push_back(student);
            cout << "Added Successfully" << endl;
        }
        else{
            string name, major;
            bool found = false;
            cin >> name >> major;
            list<Student> :: iterator itr;
            for (itr = database.begin(); itr != database.end(); itr++){
                if ((*itr).name == name && (*itr).major == major){
                    cout << "Student Number:" << (*itr).id << endl;
                    found = true;
                    break;
                }
            }
            if (found == false){
                cout << "No Record found" << endl;
            }
        }
        cin >> command;
    }
    cout << "Bye" << endl;
    return 0;
}