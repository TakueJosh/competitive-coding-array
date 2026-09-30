/*
 * Problem 3: Maximum Subarray Sum
 * Approach 1: Brute Force
 *
 * Idea:
 *   Try every possible subarray [i..j] and track the maximum sum.
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
    for (int i = 0; i < n; i++) cin >> nums[i];

    long long maxSum = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        long long currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += nums[j];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << maxSum;
    return 0;
}