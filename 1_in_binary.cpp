    #include <iostream>
    using namespace std;

    int main() {
      int k;
      cin >> k;
      for(int i=0; i<k; i++){
          int n, ans=0;
          cin >> n;
          while(n>0){
              ans+=n%2;
              n/=2;
          }
          cout <<ans<<endl;
      }
      return 0;
}