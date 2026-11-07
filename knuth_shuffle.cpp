#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void knuthShuffle(vector<int>& arr) {
    srand(time(0)); // Seed the random number generator
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); // Generate random index 0 <= j <= i
        swap(arr[i], arr[j]);    // Swap elements
    }
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5};
    knuthShuffle(array);

    cout << "Shuffled array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// this algo ensures that each permutation for an array is equally likely