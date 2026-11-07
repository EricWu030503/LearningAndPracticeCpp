    #include <iostream>
    #include <iomanip>
    #include <cmath>
    using namespace std;
   
    double mean(double x1, double x2, double x3, double x4, double x5){
        return (x1+x2+x3+x4+x5)/5;
    }

    double sd(double x1, double x2, double x3, double x4, double x5){
        double x = mean(x1,x2,x3,x4,x5);
        double std =sqrt((pow(x1-x,2)+pow(x2-x,2)+pow(x3-x,2)+pow(x4-x,2)+pow(x5-x,2))/5);
        return std;
    }

    int main() {
        double x1,x2,x3,x4,x5;
        cin >> x1 >> x2 >> x3 >> x4 >> x5;
        cout << "Mean = " << fixed << setprecision(2) << mean(x1,x2,x3,x4,x5) <<endl;
        cout << "Standard deviation = " << fixed << setprecision(2) << sd(x1,x2,x3,x4,x5);
        return 0;
}

