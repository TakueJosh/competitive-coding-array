/*
 * Problem 1: Two Sum
 * Approach 3: Hash Map (Optimal)
 *
 * Idea:
 *   Single pass. For each nums[i], check if (target - nums[i]) 
 *   has been seen before. If yes, we've found the pair.
 *   Otherwise, insert nums[i] -> i into the map.
 *
 * Time Complexity : O(n)   (average case; single pass, O(1) lookups)
 * Space Complexity: O(n)   (hash map)
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

    unordered_map<int, int> mp;   // value -> index

    for (int i = 0; i < n; i++) {
        int required = target - nums[i];

        if (mp.find(required) != mp.end()) {
            // Found the pair: (mp[required], i)
            cout << mp[required] << " " << i;
            return 0;
        }

        // Store current element with its index
        mp[nums[i]] = i;
    }

    return 0;
}