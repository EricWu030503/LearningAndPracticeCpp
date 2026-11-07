#include <iostream>
#include <string>
using namespace std;

void palindrome(string a){
    for (int i = 0 ; i < a.length() ; i++){
        if ( !( ( a[i] >= 'a' && a[i] <= 'z' ) || ( a[i] >= 'A' && a[i] <= 'Z' ) )){
            a.erase(i,1);
            i--;
        }
        else{
            a[i] = tolower(a[i]);
        }
    }
    string b = "";
    for (int i = a.length()-1 ; i >= 0 ; i--){
        b += a[i];
    }
    if ( a == b ){
        cout << "The input string is a palindrome." ; 
    }
    else{
        cout << "The input string is not a palindrome." ;
    }
    
    
    
}
int main(){
    string input;
    getline(cin, input);
    palindrome(input);
    return 0;
}