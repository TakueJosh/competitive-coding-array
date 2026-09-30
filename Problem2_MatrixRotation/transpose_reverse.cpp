/*
 * Problem 2: Rotate Matrix 90 Degrees Clockwise
 * Approach 2: Transpose + Reverse Rows (In-Place)
 *
 * Idea:
 *   1. Transpose: swap mat[i][j] with mat[j][i] for all j > i
 *   2. Reverse each row
 *   Combined, these produce a 90-degree clockwise rotation.
 *
 * Time Complexity : O(N^2)
 * Space Complexity: O(1)  (in-place)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    // Step 1: Transpose (only upper triangle, to avoid double-swapping)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }

    // Print the rotated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}