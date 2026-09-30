/*
 * Problem 3: Maximum Subarray Sum
 * Approach 2: Prefix Sum
 *
 * Idea:
 *   Build prefix sums. Then subarray sum [i..j-1] = prefix[j] - prefix[i].
 *   Try all pairs (i, j) with i < j.
 *
 * Time Complexity : O(n^2)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) cin >> nums[i];

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + nums[i - 1];

    long long maxSum = LLONG_MIN;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            maxSum = max(maxSum, prefix[j] - prefix[i]);

    cout << maxSum;
    return 0;
}