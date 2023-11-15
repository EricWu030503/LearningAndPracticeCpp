    #include <iostream>
    using namespace std;

    int main() {
      int n;
      cin >>n;
      int a[n];
      for(int i=0; i<n; i++){
          int x;
          cin >>x;
          a[n-i-1]=x;
      }
      for (int i=0; i<n; i++){
          cout<<a[i]<<" ";
      }
      return 0;
}