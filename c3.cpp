#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to check if s1 can be transformed into s2
bool canTransform(string s1, string s2) {
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    // Traverse both strings from the end
    while (i >= 0 && j >= 0) {
        if (toupper(s1[i]) == s2[j]) {
            // If characters match, move both pointers
            i--;
            j--;
        } else if (islower(s1[i])) {
            // If s1[i] is a lowercase letter, delete it
            i--;
        } else {
            // If characters don't match and s1[i] is uppercase, transformation not possible
            return false;
        }
    }

    // If all characters of s2 are matched, check if remaining characters of s1 can be deleted
    while (i >= 0) {
        if (isupper(s1[i])) {
            return false; // Cannot delete uppercase letters
        }
        i--;
    }

    // If all characters of s2 are matched, transformation is possible
    return (j < 0);
}

int main() {
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    if (canTransform(s1, s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
