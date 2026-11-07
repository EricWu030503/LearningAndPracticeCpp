#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<int>& arr, int range) {
    vector<vector<int>> buckets(range + 1); // Create buckets

    // Distribute elements into buckets
    for (int num : arr) {
        buckets[num].push_back(num);
    }

    // Concatenate sorted buckets into the output array
    int index = 0;
    for (int i = 1; i <= range; ++i) {
        for (int num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<int> arr = {4, 1, 3, 4, 2, 1, 8, 9};
    int range = 9; // Range of keys is [1, 4]
    bucketSort(arr, range);

    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
