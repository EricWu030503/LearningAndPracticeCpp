#include<iostream> 
#include<string>
#include <cstdlib>
using namespace std;

struct Employee{
    string name;
    string position;
    double salary;
};

int main(){
    Employee employeeList[10];
    for (int i = 0; i < 10; i++){
        cin >> employeeList[i].name >> employeeList[i].position >> employeeList[i].salary; 
    }
    Employee employeList2[3] = { {"Wing", "Sales", 20000}, { "Ben", "Manager", 40000},{ "David", "Clerk", 25000} };
    // An array of structure variables can be initialized with an initialization list
    return 0;
}