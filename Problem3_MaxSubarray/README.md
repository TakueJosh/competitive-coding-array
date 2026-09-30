# Problem 3: Maximum Subarray Sum

## Problem Statement
Given an array of integers `nums`, find the maximum possible sum of a 
contiguous subarray (containing at least one element).

**Input Format:**
- First line: integer `n`
- Second line: `n` space-separated integers

**Output Format:**
- Print a single integer — the maximum subarray sum.

## Sample
**Input:**
```
9
-2 1 -3 4 -1 2 1 -5 4
```

**Output:**
```
6
```

**Explanation:** The subarray `[4, -1, 2, 1]` has sum `6`, which is the maximum possible.

---

## Approaches Implemented

### 1. Brute Force — `brute_force.cpp`
Try every possible subarray `[i..j]` and track the maximum sum.

| Complexity | Value |
|------------|-------|
| Time       | O(n²) |
| Space      | O(1)  |

**Pros:** Simple.
**Cons:** Too slow for large inputs (n > 10^4).

---

### 2. Prefix Sum — `prefix_sum.cpp`
Build a prefix sum array, then compute each subarray sum in O(1). Still O(n²) overall.

| Complexity | Value |
|------------|-------|
| Time       | O(n²) |
| Space      | O(n)  |

**Pros:** Cleaner subarray-sum queries.
**Cons:** Still quadratic; not optimal for this problem alone.

---

### 3. Kadane's Algorithm (Optimal) — `kadane.cpp`
Single pass. At each index `i`, choose to:
- **Extend** the current subarray (`currentSum + nums[i]`), OR
- **Restart** from `nums[i]`.

Then update the running maximum.

| Complexity | Value |
|------------|-------|
| Time       | O(n)  |
| Space      | O(1)  |

**Pros:** Fastest possible; classic interview favorite.
**Cons:** Only returns the sum — modify to also track start/end indices if needed.

> **Key insight:** Kadane's is not a formula to memorize — it's a *decision* at every index: continue or restart.

---

## Comparison Table

| Approach      | Time  | Space | When to use                            |
|---------------|-------|-------|----------------------------------------|
| Brute Force   | O(n²) | O(1)  | Learning; tiny inputs                  |
| Prefix Sum    | O(n²) | O(n)  | When subarray-sum queries are reused   |
| Kadane        | O(n)  | O(1)  | **Best general solution**              |

---

## Edge Cases Covered
- ✅ **All negatives** (e.g. `-3 -4 -2 -1 -5`) → returns `-1` (must include at least one element)
- ✅ **Single element** → returns that element
- ✅ **All positives** → returns sum of whole array
- ✅ **Zeros** → handled naturally by Kadane
- ✅ **Mixed signs** → correct due to `max(nums[i], currentSum + nums[i])` restart logic

---

## How to Compile & Run
```bash
g++ brute_force.cpp -o brute_force && ./brute_force
g++ prefix_sum.cpp -o prefix_sum && ./prefix_sum
g++ kadane.cpp -o kadane && ./kadane
```

---

## Sample Test Cases

| Input                                 | Expected Output |
|---------------------------------------|-----------------|
| `9 / -2 1 -3 4 -1 2 1 -5 4`           | `6`             |
| `5 / -3 -4 -2 -1 -5`                  | `-1`            |
| `1 / 5`                               | `5`             |
| `5 / 1 2 3 4 5`                       | `15`            |
| `4 / -1 0 -2 -3`                      | `0`             |

---

## Practice Variations
- **Circular Kadane** → maximum sum subarray in a circular array
- **Maximum product subarray** → similar idea, track min and max
- **2D Maximum Sum Submatrix** → Kadane on rows
- **Print subarray indices** → track `start`, `end`, and `tempStart`