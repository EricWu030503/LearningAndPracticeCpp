#include <iostream>
#include <string>

using namespace std;



string reverse( string s )
{
    if (s.length() == 1){
        return s;
    }
	return s[s.length()-1]+reverse(s.substr(0,s.length()-1));
}






int main()
{
	string s;
	cin >> s;

	cout << "String in reverse = " << reverse(s) << endl;
    
	return 0;

}