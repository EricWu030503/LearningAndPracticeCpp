#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int range) { //O(n+k), where n is num of elements, and k is the range. When k is O(n), sorting is O(n).
    vector<int> count(range + 1, 0); // Count array to store frequencies

    // Count the occurrences of each element
    for (int num : arr) {
        count[num]++;
    } // O(n)

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 1; i <= range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    } // O(n+k)
}
