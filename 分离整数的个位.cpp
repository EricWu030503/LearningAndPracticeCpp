    #include <iostream>
    using namespace std;
   
   int main() {
    int num;
    cin >>num;

    int n3=num/100;
    num-=100*n3;
    int n2=num/10;
    int n1=num-10*n2;
    cout <<n3<<endl;
    cout <<n2<<endl;
    cout <<n1;
    return 0;
}