#include <iostream>
using namespace std;

void print_array( int a[], int size );
void swap( int &a, int &b );
void selection_sort( int a[], int size );

int main(){
    const int size = 5;
    int score[size] = { 80, 100, 63, 70, 52};
    cout << "Original array: " << endl;
    print_array( score, size ); 
    selection_sort( score, size );
    cout << "Sorted array: " << endl;
    print_array( score, size );
    return 0; 
}

void swap( int &a, int &b ){
    int tmp = a; 
    a = b; 
    b = tmp; 
}

void print_array( int a[], int size ){
    int i;
    for ( i = 0 ; i < size ; i++){
        cout << a[i] << " "; 
    }
    cout << endl; 
}

void selection_sort( int a[], int size ){
    int i, j;
    int min_value; 
    int slot_id_of_min_value; 
    // i indicates the i-th iteartion
    for( i = 0 ; i < size - 1; i++ ){
        // Initialize min_value and the slot_id in each iteration
        min_value = a[i];
        slot_id_of_min_value = i;
        // Find the minimum in the i-th iteration
        for( j = i ; j < size ; j++ ){
            if ( a[j] < min_value ){
                min_value = a[j];
                slot_id_of_min_value = j; 
            } 
        }
        swap( a[i], a[slot_id_of_min_value] );
    } 
}