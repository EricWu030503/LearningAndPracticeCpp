    #include <iostream>
    #include <cmath>
    using namespace std;    

    double mean(double nums[],int len){
        double sum = 0;
        for (int i = 0 ; i < len ; i++){
            sum += nums[i];
        }
        return sum/len;
    }

    double Var(double nums[],int len){
        double x = mean(nums,len);
        double sum = 0;
        for (int i = 0 ; i < len ; i++){
            sum += pow(nums[i]-x,2);
        }
        double var = sum/len;
        return var;
    }

    int main() {
        int len;
        cin >> len;
        double nums[20];
        for (int i = 0; i < len ; i++){
            double input;
            cin >> input;
            nums[i] = input;
        }
        cout << Var(nums,len);
        return 0;
}
