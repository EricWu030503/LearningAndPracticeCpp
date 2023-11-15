#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Employee{
    string name;
    string position;
    double salary;
};

struct Company{
    string name;
    string address;
    int numOfEmployee;
    Employee employeeList[100];
};

void addEmployee(Company & c){
    cout << "Add an employee in ";
    cout << c.name << endl;
    int id = c.numOfEmployee;
    cout << "Name of Employee? ";
    cin >> c.employeeList[id].name;
    cout << "Position of Employee? ";
    cin >> c.employeeList[id].position;
    cout << "Salary of Employee? ";
    cin >> c.employeeList[id].salary; 
    c.numOfEmployee++;
}

void printCompanyInfo(Company c){
    cout << "Company name: " << c.name << endl;
    cout << "Address: " << c.address << endl;
    cout << "Number of Employee: " << c.numOfEmployee << endl; 
    for ( int i = 0 ; i < c.numOfEmployee ; i++){
        cout << "----Employee ------" << endl;
        cout << c.employeeList[i].name << endl;
        cout << c.employeeList[i].position << endl;
        cout << "$" << c.employeeList[i].salary << endl;
        cout << "-------------------" << endl; 
} 
}

int main(){
    Company c1;
    c1.name = "ABC company";
    c1.address = "Hong Kong";
    c1.numOfEmployee = 0;
    Company c2;
    c2.name = "XYZ company";
    c2.address = "U.S.";
    c2.numOfEmployee = 0; 
    addEmployee(c1);
    addEmployee(c1);
    addEmployee(c2); 
    printCompanyInfo(c1); 
}

/*
Structures can also be nested so that a member of a 
structure can also be in turn another structure
*/