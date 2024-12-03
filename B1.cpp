#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum number of shops visited
int maxShopsVisited(vector<int> &S, vector<int> &E, int K) {
    int n = S.size();
    vector<pair<int, int>> shops(n);

    // Step 1: Combine start and end times and sort by ending times
    for (int i = 0; i < n; i++) {
        shops[i] = {E[i], S[i]};
    }
    sort(shops.begin(), shops.end()); // Sort by ending times

    // Step 2: Maintain the end times of shops visited by each person
    vector<int> endTimes(K, -1);
    int count = 0;

    // Step 3: Iterate through the shops
    for (const auto &shop : shops) {
        int start = shop.second;
        int end = shop.first;

        // Assign the shop to the first available person
        for (int i = 0; i < K; i++) {
            if (start > endTimes[i]) { // Person is free
                endTimes[i] = end;    // Update their end time
                count++;
                break; // Move to the next shop
            }
        }
    }

    return count;
}

int main() {
    // Example 1
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum shops visited (Example 1): " << maxShopsVisited(S1, E1, K1) << endl;

    // Example 2
    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum shops visited (Example 2): " << maxShopsVisited(S2, E2, K2) << endl;

    return 0;
}
