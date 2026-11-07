#include <iostream>
using namespace std;

// Node structure for the linked list
struct ListNode {
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

// Function to detect the beginning of the cycle in the linked list
ListNode* detectCycleStart(ListNode* head) {
    if (!head || !head->next) {
        return nullptr; // No cycle if the list is empty or has only one node
    }

    ListNode* slow = head; // Slow pointer moves one step at a time
    ListNode* fast = head; // Fast pointer moves two steps at a time

    // Step 1: Detect if a cycle exists
    while (fast && fast->next) {
        slow = slow->next;          // Move slow pointer by one step
        fast = fast->next->next;    // Move fast pointer by two steps

        if (slow == fast) { // Cycle detected
            // Step 2: Find the start of the cycle
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next; // Move both pointers one step at a time
                slow = slow->next;
            }
            return entry; // The start of the cycle
        }
    }

    return nullptr; // No cycle found
}

int main() {
    // Create a linked list with a cycle
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Create a cycle (pointing to node 2)

    // Detect the start of the cycle
    ListNode* cycleStart = detectCycleStart(head);

    if (cycleStart) {
        cout << "Cycle detected at node with value: " << cycleStart->value << endl;
    } else {
        cout << "No cycle detected in the linked list!" << endl;
    }

    // Clean up memory (note: won't fully free memory in case of a cycle)
    delete head->next->next->next; // Free node 4
    delete head->next->next;       // Free node 3
    delete head->next;             // Free node 2
    delete head;                   // Free node 1

    return 0;
}
