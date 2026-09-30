# Problem 2: Rotate a 2D Matrix by 90° Clockwise

## Problem Statement
Given a square matrix of size N × N, rotate the matrix 90 degrees clockwise.

**Input Format:**
- First line: integer `N`
- Next N lines: N space-separated integers per line

**Output Format:**
- Print the rotated matrix, each row on a new line with space-separated values.

## Sample
**Input:**

3
1 2 3
4 5 6
7 8 9


**Output:**

7 4 1
8 5 2
9 6 3


**Explanation:** The first row `1 2 3` becomes the last column `3 6 9` (read bottom-up). Rotating each element 90° clockwise yields the output.

---

## Approaches Implemented

### 1. Extra Matrix — `extra_matrix.cpp`
Create a new matrix and fill it using the index mapping:

rotated[i][j] = mat[n - j - 1][i]


| Complexity | Value  |
|------------|--------|
| Time       | O(N²)  |
| Space      | O(N²)  |

**Pros:** Simple, easy to reason about.
**Cons:** Uses an extra matrix — not in-place.

---

### 2. Transpose + Reverse Each Row — `transpose_reverse.cpp`
**Two-step in-place rotation:**
1. **Transpose** the matrix: swap `mat[i][j]` ↔ `mat[j][i]` for all `j > i` (only upper triangle).
2. **Reverse** each row.

Why this works: Transposing swaps rows ↔ columns; reversing rows converts this to a clockwise rotation.

| Complexity | Value  |
|------------|--------|
| Time       | O(N²)  |
| Space      | O(1)   |

**Pros:** Truly in-place — no extra matrix needed.
**Cons:** Two passes over the matrix.

---

### 3. Layer-by-Layer 4-Way Swap — `layer_swap.cpp`
Rotate the matrix **ring by ring**, from the outer layer to the innermost. For each ring, perform a **4-way swap** on every group of 4 corresponding cells:

top → right → bottom → left → top


Implemented with a single temporary variable (no extra matrix, no intermediate transpose).

| Complexity | Value  |
|------------|--------|
| Time       | O(N²)  |
| Space      | O(1)   |

**Pros:** Pure in-place, single pass, only one temp variable.
**Cons:** Trickier to reason about — classic interview "gotcha."

> **Key detail:** We loop `for (int j = i + 1; j < n; j++)` in the transpose step to avoid swapping pairs twice (which would undo them).

---

## Comparison Table

| Approach              | Time  | Space | In-place? | When to use                        |
|-----------------------|-------|-------|-----------|------------------------------------|
| Extra Matrix          | O(N²) | O(N²) | No        | Quick prototype, readability       |
| Transpose + Reverse   | O(N²) | O(1)  | Yes ✅    | Clean in-place, easy to remember   |
| Layer 4-Way Swap      | O(N²) | O(1)  | Yes ✅    | Pure math rotation, interview-ready|

---

## Edge Cases Covered
- ✅ **1×1 matrix** — no rotation needed; outer loop condition `layer < n/2` prevents any work
- ✅ **2×2 matrix** — single layer, inner loop runs once
- ✅ **Even N** — all rings fully rotated
- ✅ **Odd N** — center element stays in place (correct behavior)

---

## How to Compile & Run
```bash
g++ extra_matrix.cpp -o extra_matrix && ./extra_matrix
g++ transpose_reverse.cpp -o transpose_reverse && ./transpose_reverse
g++ layer_swap.cpp -o layer_swap && ./layer_swap


