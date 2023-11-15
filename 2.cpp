    #include <iostream>
    using namespace std;
   
    bool is_composite(int n){
        if (n == 1 || n == 2){
            return false;
        }
        else{
            for(int i = 2; i < n; i++){
                if (n%i == 0){
                    return true;
                }
            }
            return false;
        }
    }

    void composite_numbers(int M, int N){
        for(int i = M; i <= N; i++){
            if (is_composite(i)){
                cout << i << endl;
            }
        }
    }
    int main() {
        int M , N;
        cin >> M >> N;
        composite_numbers(M,N);
        return 0;
}