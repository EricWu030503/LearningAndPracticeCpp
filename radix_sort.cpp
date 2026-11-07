#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A utility function to get the maximum value in an array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        maxVal = max(maxVal, num);
    }
    return maxVal;
}

// Counting Sort used as a subroutine for Radix Sort
void countingSort(vector<int>& arr, int exp) { //stable sorting algo that maintains the relative order of numbers with same digit
    int n = arr.size(); 
    vector<int> output(n);   // Output array to hold sorted elements
    vector<int> count(10, 0); // Count array for the range of digits (0-9)

    // Count the occurrences of each digit at the current place value
    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Modify count array to store cumulative counts
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr);

    // Sort the array for each digit's place value (1s, 10s, 100s, etc.)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Main function to test Radix Sort
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Time Complexity Analysis of Radix Sort:
 * ---------------------------------------
 * Let:
 * - n = Number of elements in the array.
 * - d = Number of digits in the largest number.
 * - k = Range of digits (for base 10, k = 10).
 *
 * For each digit (d passes), we perform Counting Sort, which takes:
 * - O(n + k), where n is the size of the array and k is the range of digits.
 *
 * Total time complexity:
 * - O(d * (n + k)).
 *
 * Special Cases:
 * 1. When k is constant (e.g., base 10):
 *    - Time complexity simplifies to O(d * n).
 *
 * Radix Sort is efficient when:
 * - The number of digits (d) is small.
 * - The range of digits (k) is small relative to n.
 */
