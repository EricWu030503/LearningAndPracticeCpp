#include <iostream>
using namespace std;

void move(int n, char src, char des, char tmp) {
    if (n == 1){
    cout << "Move disk from " << src << " to " << des << endl;
        }
    else {
        move( n-1, src, tmp, des);
        move( 1, src, des, tmp);
        move( n-1, tmp, des, src);
        }
    }

int main(){
    int n;
    char src,des,tmp;
    cout << "Input number of disks: ";
    cin >> n;
    cout << "Input the source rod: ";
    cin >> src;
    cout << "Input the destination rod: ";
    cin >> des;
    cout << "Input the intermediate rod: ";
    cin >> tmp;
    move(n,src,des,tmp);
}