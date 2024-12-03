#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Function to generate all distinct subsets
vector<vector<int>> findDistinctSubsets(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort the array to handle duplicates
    set<vector<int>> uniqueSubsets;
    int n = nums.size();

    // Generate all subsets using bit masking
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        uniqueSubsets.insert(subset);
    }

    // Convert set to vector
    return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
}

int main() {
    vector<int> nums;
    int n, num;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> subsets = findDistinctSubsets(nums);

    cout << "Distinct subsets are:\n";
    for (const auto& subset : subsets) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i] << (i < subset.size() - 1 ? ", " : "");
        }
        cout << "}\n";
    }

    return 0;
}
