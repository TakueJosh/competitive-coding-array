/*
 * Problem 1: Two Sum
 * Approach 1: Brute Force
 *
 * Idea:
 *   Check every pair (i, j) with i < j.
 *   If nums[i] + nums[j] == target, print i and j.
 *
 * Time Complexity : O(n^2)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    // Try every pair
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                cout << i << " " << j;
                return 0;
            }
        }
    }

    return 0;
}