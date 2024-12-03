#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of ways to make the sum using coins
int countWaysToMakeSum(int sum, vector<int> &coins) {
    int n = coins.size();
    vector<int> dp(sum + 1, 0);

    dp[0] = 1; // Base case: One way to make sum 0 (no coins used)

    for (int coin : coins) {
        for (int i = coin; i <= sum; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[sum];
}

int main() {
    int sum1 = 4;
    vector<int> coins1 = {1, 2, 3};
    cout << "Number of ways (Test Case 1): " << countWaysToMakeSum(sum1, coins1) << endl;

    int sum2 = 10;
    vector<int> coins2 = {2, 5, 3, 6};
    cout << "Number of ways (Test Case 2): " << countWaysToMakeSum(sum2, coins2) << endl;

    return 0;
}
