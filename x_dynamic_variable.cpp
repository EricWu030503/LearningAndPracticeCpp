#include <iostream>
using namespace std;

int main(){
    int *p;
    string *s; 
    p = new int; // Reserves cell from the free store for storing int value. After assigning the memory cell, the new int returns the address of this newly reserved cell.
    s = new string; 
    *p = 8; 
    *s = "dragon";
    return 0; 
}

/*
When the program is put into execution, 
variables declared in the program such 
as int, double, char, string, array, struct, 
pointer …etc are stored in the ordinary 
memory.

There are also free store memory that 
we can use for dynamic memory 
allocation.
*/