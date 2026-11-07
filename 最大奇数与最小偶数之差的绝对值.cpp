    #include <iostream>
    using namespace std;
   
   int main() {
    int a[6];
    int max_odd=0;
    int min_even=101;
    for (int i=0;i<6;i++){
        cin >>a[i];
        if (a[i]%2==1&&a[i]>max_odd){
            max_odd=a[i];
        }
        else if(a[i]%2==0&a[i]<min_even){
            min_even=a[i];
        }
    }
    cout <<abs(max_odd-min_even);

    return 0;
}