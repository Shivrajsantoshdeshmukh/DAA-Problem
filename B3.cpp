#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if the work can be completed within D days with given maxWorkPerDay
bool isPossible(const vector<int> &tasks, int D, int maxWorkPerDay) {
    int daysRequired = 1;
    int currentWork = 0;

    for (int task : tasks) {
        if (task > maxWorkPerDay) {
            return false; // A single task exceeds maxWorkPerDay
        }

        if (currentWork + task <= maxWorkPerDay) {
            currentWork += task;
        } else {
            daysRequired++;
            currentWork = task;

            if (daysRequired > D) {
                return false;
            }
        }
    }

    return true;
}

// Function to find the minimum work per day to complete all tasks within D days
int minimumWorkPerDay(const vector<int> &tasks, int D) {
    int low = *max_element(tasks.begin(), tasks.end()); // Minimum possible max work per day
    int high = accumulate(tasks.begin(), tasks.end(), 0); // Maximum possible max work per day
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(tasks, D, mid)) {
            result = mid;
            high = mid - 1; // Try for a smaller maxWorkPerDay
        } else {
            low = mid + 1; // Increase maxWorkPerDay
        }
    }

    return result;
}

int main() {
    vector<int> tasks1 = {3, 4, 7, 15};
    int D1 = 10;
    cout << "Minimum work per day (Test Case 1): " << minimumWorkPerDay(tasks1, D1) << endl;

    vector<int> tasks2 = {30, 20, 22, 4, 21};
    int D2 = 6;
    cout << "Minimum work per day (Test Case 2): " << minimumWorkPerDay(tasks2, D2) << endl;

    return 0;
}
