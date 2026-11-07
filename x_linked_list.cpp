#include <iostream>
using namespace std;


struct Product{
    string name;
    double price;
    Product *next; // used to store the address of the next struct variable
};

Product * headInsert (Product *h, string n, double p){
    Product *pNode = new Product;
    pNode -> name = n;
    pNode -> price = p;
    // create a new node
    pNode -> next = h;
    // New node’s next is the first node.
    h = pNode;
    // Head points to the new node.
    return h; 
}

void searchList (Product *head, string n){
    Product *current;
    current = head;
    while (current != NULL){
        if (current -> name == n){
            cout << current-> price << endl;
        }
        current = current -> next;  
    } 
}

void deleteNode(Product *head, string n){
    Product *current = head, *previous = NULL;
    while (current != NULL){
        if (current -> name == n){
            previous -> next = current -> next;
            delete current;
            break; 
        }
        previous = current;
        current = current -> next;
    }
}
// delete the non-first node

int main(){
    Product *head = NULL;
     /*
    In order to access a linked list, a pointer variable often 
    called head is used to store a pointer to the first node 
    of the list.  

    Initially when the linked list is empty (i.e., a linked list 
    with no nodes), head will simply contain a NULL pointer.   
    */
    head = headInsert(head, "chicken", 30);
    searchList(head, "chicken");
    return 0;
}

/*

A fundamental data structure.

Allow insertion and removal of items (struct) at any 
point in the list in constant time (efficient).

Make use of the concepts of structure (struct), 
pointers (*ptr) and dynamic variable allocation (new).

A NULL pointer is assigned the pointer variable of the 
last node to indicate the end of the linked list.
*/