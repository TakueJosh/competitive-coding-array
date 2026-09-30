/*
 * Problem 2: Rotate Matrix 90 Degrees Clockwise
 * Approach 1: Extra Matrix
 *
 * Idea:
 *   Create a new matrix. Place each element at its rotated position
 *   using the mapping: rotated[i][j] = mat[n - j - 1][i]
 *
 * Time Complexity : O(N^2)
 * Space Complexity: O(N^2)   (extra matrix)
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

    // Create rotated matrix using index mapping
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[i][j] = mat[n - j - 1][i];
        }
    }

    // Print the rotated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << rotated[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}