/*
 * Problem 2: Rotate Matrix 90 Degrees Clockwise
 * Approach 3: Layer-by-Layer 4-Way Swap (Pure In-Place)
 *
 * Idea:
 *   Process the matrix ring by ring (outer → inner).
 *   For each ring, rotate 4 corresponding cells at once:
 *      top → right → bottom → left → top
 *
 * Time Complexity : O(N^2)
 * Space Complexity: O(1)   (in-place, only one temp variable)
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

    // Rotate each layer
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;           // first row/col of this layer
        int last  = n - layer - 1;   // last  row/col of this layer

        for (int i = first; i < last; i++) {
            int offset = i - first;

            // Save top
            int top = mat[first][i];

            // left → top
            mat[first][i] = mat[last - offset][first];

            // bottom → left
            mat[last - offset][first] = mat[last][last - offset];

            // right → bottom
            mat[last][last - offset] = mat[i][last];

            // top → right
            mat[i][last] = top;
        }
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