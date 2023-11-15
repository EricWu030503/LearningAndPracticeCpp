#include<iostream> 
#include<string>
#include <cstdlib>
using namespace std;

struct Employee{
    string name;
    string position;
    double salary;
};

Employee createEmployee(){
    Employee e;
    cout << "Name of Employee? ";
    cin >> e.name;
    cout << "Position of Employee? ";
    cin >> e.position; 
    cout << "Salary of Employee? ";
    cin >> e.salary;
    return e; 
}

void showEmployeeInfo(Employee e){
    cout << endl;
    cout << "----- Employee Info -----"<<endl;
    cout << "Name: " << e.name << endl;
    cout << "Position: " << e.position << endl;
    cout << "Salary: " << e.salary << endl; 
    cout << "------------------------------"<<endl;
}

void salaryRaise(Employee & e , double factor){
    e.salary *= factor; 
}

int main(){
    Employee e1;
    e1 = createEmployee();
    showEmployeeInfo( e1 );
    salaryRaise( e1, 1.1);
    showEmployeeInfo( e1 );
    return 0;
}

/*
Structure variables can be passed to a function either by value or by reference like 
regular variables and can be returned by a function.
*/