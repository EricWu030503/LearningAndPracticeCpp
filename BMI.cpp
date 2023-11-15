#include <iostream>
using namespace std;
int main(){
   double weight, height;
   cin >> weight >> height;
   double bmi = weight/(height*height);
   cout << "Your BMI = " << bmi <<endl;
   cout << "BMI VALUES" <<endl;
   cout << "Underweight: less than 18.5" <<endl;
   cout << "Normal: between 18.5 and 24.9" <<endl;
   cout << "Overweight: between 25 and 29.9" <<endl;
   cout << "Obese: 30 or greater" <<endl;
}