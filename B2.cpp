#include <iostream>
#include <vector>
using namespace std;

int maximizeProfit(vector<int> &arr) {
    int n = arr.size();
    if (n < 2) return 0; // No profit possible with less than 2 days

    int minPrice = arr[0]; // Minimum price to buy
    int maxProfit = 0;     // Maximum profit

    for (int i = 1; i < n; i++) {
        // Calculate profit if sold today
        int profit = arr[i] - minPrice;

        // Update maximum profit
        maxProfit = max(maxProfit, profit);

        // Update minimum price
        minPrice = min(minPrice, arr[i]);
    }

    return maxProfit;
}

int main() {
    vector<int> arr1 = {2, 3, 5};
    vector<int> arr2 = {8, 5, 1};

    cout << "Maximum Profit (Test Case 1): " << maximizeProfit(arr1) << endl; // Output: 5
    cout << "Maximum Profit (Test Case 2): " << maximizeProfit(arr2) << endl; // Output: 0

    return 0;
}
