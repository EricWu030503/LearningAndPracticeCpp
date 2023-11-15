#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;



int main(){
    ifstream fin;
    fin.open("temperature.txt");
    ofstream fout;
    fout.open("average.txt");
    if (fin.fail() || fout.fail()){
        cout << "Fail to open the file" << endl;
    }
    else{
        double sum = 0, average = 0;
        string temp, line, date;

        while (getline(fin, line)){
            istringstream iss(line);
            iss >> date;
            fout << date << " ";
            while (iss >> temp){
                sum += stod(temp);
            }
            average = sum / 24;
            fout << fixed << setprecision(1) << average << endl;
            sum = 0;
        }
        fin.close();
        fout.close();
    }
    return 0;
}