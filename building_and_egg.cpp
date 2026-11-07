#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to calculate the minimum number of drops needed to determine the critical floor in the worst case.
int eggDrop(int k, int n) {
    // dp[i][j] represents the minimum number of drops needed for i eggs and j floors
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    dp[0][0] = -1;
    
    // If there's no egg, we cannot find the required number.
    // If there is only 1 egg, we need to drop it sequentially from the 1st floor to the nth floor.
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = -1;
        dp[1][j] = j;
    }

    // If there are 0 floors, 0 drops are needed. For 1 floor, 1 drop is needed.
    for (int i = 1; i <= k; ++i) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    // Fill the dp table for the general case.
    for (int i = 2; i <= k; ++i) { // Iterate over the number of eggs
        for (int j = 2; j <= n; ++j) { // Iterate over the number of floors
            dp[i][j] = INT_MAX;

            // Test dropping the egg from each floor x (1 to j)
            for (int x = 1; x <= j; ++x) {
                // If the egg breaks at floor x, check below (i-1 eggs, x-1 floors).
                // If the egg does not break, check above (i eggs, j-x floors).
                int worstCase = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);

                // Find the minimum number of drops in the worst case.
                dp[i][j] = min(dp[i][j], worstCase);
            }
        }
    }

    // Return the result for k eggs and n floors.
    return dp[k][n];
}

int main() {
    int k, n;
    cout << "Enter the number of eggs: ";
    cin >> k;
    cout << "Enter the number of floors: ";
    cin >> n;

    // Calculate and display the result.
    int result = eggDrop(k, n);
    cout << "Minimum number of drops needed in the worst case with " << k << " eggs and " << n << " floors is: " << result << endl;

    return 0;
}
