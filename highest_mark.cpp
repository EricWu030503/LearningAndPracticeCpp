    #include <iostream>
    using namespace std;
   
   int main() {
    int n;
    cin >> n;
    int max=0;
    for (int i=0; i<n; i++){
        int mark;
        cin >> mark;
        if (mark>max){
            max=mark;
        }
    }
    cout <<max;

    return 0;
}