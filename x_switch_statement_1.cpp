    #include <iostream>
    #include <string>
    using namespace std;
   
    int main() {
      int mark;
    cout << "Enter the mark: ";
    cin >> mark;
    switch ( mark / 10 ) {
    case 0: case 1:
    case 2: case 3:
    case 4: case 5:
    cout << "The grade is F." << endl;
    case 6:
    cout << "The grade is D." << endl;
    case 7:
    cout << "The grade is C." << endl;
    case 8:
    cout << "The grade is B." << endl;
    case 9:
    case 10:
    cout << "The grade is A." << endl; 
    default:
    cout << "Invalid mark." << endl; }
    return 0;
    }
