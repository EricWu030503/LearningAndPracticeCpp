    #include <iostream>
    #include <string>
    using namespace std;
   
   long factorial(int n){
        if (n == 0){
            return 1;
        }
        else{
            return n*factorial(n-1);
        }
   }

   int main() {
        long num=factorial(39);
        cout << num;
        return 0;
}
