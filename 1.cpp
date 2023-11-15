#include<iostream> 
#include<string> 
#include<algorithm> 
#include<map> 
#include<vector> 
// You can add more libraries here (if needed) 
using namespace std; 
// Define structure, classes, and member functions
struct Student {
    int id;
    string name;
    Student() {
        int id = 0;
        string name = "invalid";
    };
    Student(int inputid, string inputname) {
        id = inputid;
        name = inputname;
    };
};

class Table {
    public:
        void InsertStudent(Student x, int y); 
        void SearchbyID(int x); 
        void SearchbyGrade(int y); 
        void Statistics(); 
        void PrintAll(); 
    // You can add more functions if you want.
    private: 
        map<Student,int> records;
};

bool operator<(const Student&a, const Student&b) {
    return a.id < b.id;
}

//insert one record into the stored records
void Table::InsertStudent(Student x, int y) {
    if (records.count(x) == 0){
        records[x] = y;
    }
    else{
        cout << "Student exists." << endl;
    }
}

//return the name and grade of the student with id x
void Table::SearchbyID(int x) {
    bool found = false;
	map<Student, int> :: iterator itr;
    for (itr = records.begin(); itr != records.end(); itr++){
        if (itr->first.id == x){
            found = true;
            cout << itr->first.name << endl;
            cout << itr->second << endl;
        }
    }
    if (!found){
        cout << "No such student." << endl;
    }
}

//return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
    bool found = false;
	map<Student, int> :: iterator itr;
    for (itr = records.begin(); itr != records.end(); itr++){
        if (itr->second == y){
            found = true;
            cout << itr->first.id << " " << itr->first.name << endl;
        }
    }
    if (!found){
        cout << "No such record." << endl;
    }
}

void Table::Statistics() {
    vector<int> grades;
    map<Student, int> :: iterator itr;
    for (itr = records.begin(); itr != records.end(); itr++){
        grades.push_back(itr->second);
    }
    for (int i = 0; i < grades.size() - 1; i++) {
        for (int j = 1; j < grades.size() - i; j++) {      
            if (grades[j - 1] > grades[j]) {
                int temp = grades[j];
                grades[j] = grades[j - 1];
                grades[j - 1] = temp;
            }    
      }  
    }
    double max = grades[grades.size()-1];
    double min = grades[0];
    double median;
    if (grades.size()%2 == 1){
        median = grades[grades.size()/2];
    }
    else{
        median = (grades[grades.size()/2-1]+grades[grades.size()/2])/2.0;
    }
    cout << "Maximum " << max << endl;
    cout << "Median " << median << endl;
    cout << "Minimum " << min << endl;

}

//Print all records in the ascending order of id
void Table::PrintAll() {
    map<Student, int> :: iterator itr;
    for (itr = records.begin(); itr != records.end(); itr++){
        cout << (*itr).first.id << " " << (*itr).first.name << " " << (*itr).second << endl;
    }
}

int main() { 
    Table t;
    string command;
    int id;
    string name;
    int grade; 
    while (cin >> command) {
        if (command == "InsertStudent") {
            cin >> id >> name >> grade;
            Student s = {id, name};
            t.InsertStudent(s, grade);
        }
        else if (command == "SearchbyID") {
            cin >> id;
            t.SearchbyID(id);
        }
        else if (command == "SearchbyGrade") {
            cin >> grade;
            t.SearchbyGrade(grade);
        }
        else if (command == "PrintAll") {
            t.PrintAll();
        }
        else if (command == "Statistics") {
            t.Statistics();
        }
        else if (command == "exit") {
            break;
        }
    }
    return 0; 
}