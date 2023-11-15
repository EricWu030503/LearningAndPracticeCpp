#include <iostream> 
using namespace std; 
int main()
{
char c = 'Y';
// convert a letter from upper case to lower case 
c = c + ('a' - 'A');
cout << "1: " << c << endl;
// advance to the next character 
c = c + 1;
cout << "2: " << c << endl;
return 0;
}