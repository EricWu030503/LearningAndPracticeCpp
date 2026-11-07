 #include <iostream>
    #include <string>
    using namespace std;
   
   int main() {
    int a=4,b=3,c=2;
    a += b += c;
  
    a *= b *= c;
   
    a += b %= c;
   
    (a += b) *= c;
   
}
