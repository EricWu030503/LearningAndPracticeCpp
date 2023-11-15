    #include <iostream>
    using namespace std;
   
   char CaesarShift(char c, int k){
       if (isupper(c)) {
          int position = c - 65;
          position += k;
          position %= 26; 
          if (position < 0){
            position += 26;
          } 
          c = position + 65;
          c = tolower(c);
          return c;
       }
       else if(islower(c)){
        int position = c - 97;
        position += k;
        position %= 26; 
         if (position < 0){
            position += 26;
          } 
        c = position + 97;
        c = toupper(c);
        return c;
       }
       else{
        return c;
       }
   }


   int main() {
    char s;
    int k;
    cin >> s >> k;
    int k1 = k/10000;
    int k2 = (k-k1*10000)/100;
    int k3 = k-k1*10000-k2*100;
    if (s == 'd'){
        k1 = -k1;
        k2 = -k2;
        k3 = -k3;
    }
    int i = 1;
    char input;
    while (true){
        cin >> input;
        if (input == '!'){
            cout << '!' << ' ' << endl;
            break;
        }
        if (i % 3 == 1){
            cout << CaesarShift(input,k1) << ' ';
        }
        else if (i % 3 ==2){
            cout << CaesarShift(input,k2) << ' ';
        }
        else{
            cout << CaesarShift(input,k3) << ' ';
        }
        i++;
    }
    return 0;
}
