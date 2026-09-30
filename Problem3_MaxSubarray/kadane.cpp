/*
 * Problem 3: Maximum Subarray Sum
 * Approach 3: Kadane's Algorithm (Optimal)
 *
 * Idea:
 *   At each index, decide whether to:
 *     - extend the current subarray (currentSum + nums[i]), OR
 *     - restart from nums[i].
 *   Track the overall maximum seen.
 *
 * Time Complexity : O(n)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    long long currentSum = nums[0];
    long long maxSum = nums[0];

    for (int i = 1; i < n; i++) {
        currentSum = max((long long)nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum;
    return 0;
}