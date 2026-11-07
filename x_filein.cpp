#include<fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    ifstream file;
    file.open("price_list.txt");
    if (file.fail()){
        cout << "Fail to open the file" << endl;
    }
    else{
        string x;
        string name[10];
        double price[10];
        for (int i = 0 ; i < 10 ; i++){
            file >> name[i]; //space is used as delimiter as default
            file >> price[i];
        }
        file.close();
    }
    return 0;
}
