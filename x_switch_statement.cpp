    #include <iostream>
    #include <string>
    using namespace std;
   
    int main() {
        int mark=55;
        char grade;
        switch ( mark / 10 ) {
            case 0: case 1:
            case 2: case 3:
            case 4: case 5:
            grade = 'F';
            break;
            case 6:
            grade = 'D';
            break;
            case 7:
            grade = 'C';
            break;
            case 8:
            grade = 'B';
            break;
            case 9:
            case 10:
            grade = 'A';
            break;
            default:
            cout << "invalid mark";
         }
        cout <<grade;
    }