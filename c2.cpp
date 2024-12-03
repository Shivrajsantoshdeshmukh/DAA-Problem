#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(const vector<int>& set, int sum) {
    int n = set.size();
    
    // Create a 2D array to store the subset sum solutions
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    // If sum is 0, then solution is true (empty set is a valid subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The value in dp[n][sum] will be true if the sum is possible
    return dp[n][sum];
}

int main() {
    vector<int> set1 = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    cout << (isSubsetSum(set1, sum1) ? "True" : "False") << endl;

    vector<int> set2 = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    cout << (isSubsetSum(set2, sum2) ? "True" : "False") << endl;

    return 0;
}
