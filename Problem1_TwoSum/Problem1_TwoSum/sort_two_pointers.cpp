/*
 * Problem 1: Two Sum
 * Approach 2: Sorting + Two Pointers
 *
 * Idea:
 *   Store {value, original_index} pairs, sort by value,
 *   then use two pointers from both ends.
 *
 * Time Complexity : O(n log n)  (sorting dominates)
 * Space Complexity: O(n)        (extra vector of pairs)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> nums;   // {value, original_index}
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back({x, i});
    }

    int target;
    cin >> target;

    // Sort by value
    sort(nums.begin(), nums.end());

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = nums[left].first + nums[right].first;

        if (sum == target) {
            cout << nums[left].second << " " << nums[right].second;
            return 0;
        }
        else if (sum < target) {
            left++;   // need a bigger sum
        }
        else {
            right--;  // need a smaller sum
        }
    }

    return 0;
}