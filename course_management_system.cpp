// Handling user commands

#include <iostream>
#include <string>
using namespace std;

struct Course{
    string code, name, lecturer;
};



int main() {
    Course courses[100];
    int count = 0;
	string input;
	cin >> input;
	while (input != "exit") {
		if (input == "add") {
			cin >> courses[count].code >> courses[count].name >> courses[count].lecturer;
            count ++;
		}
		if (input == "show") {
            string course_code;
			cin >> course_code;
            for (int i = 0; i < count; i++){
                if (courses[i].code == course_code){
                    cout << "Name: " << courses[i].name << ", Lecturer: " << courses[i].lecturer << endl;
                }
            }
		}
		cin >> input;
	}
	return 0;
}