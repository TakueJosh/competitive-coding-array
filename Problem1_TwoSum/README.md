# Problem 1: Two Sum

## Problem Statement
Given an array of integers `nums` and an integer `target`, find the indices 
of the two distinct elements whose sum equals `target`.

**Constraints:**
- Exactly one valid solution exists.
- You may not use the same element twice.
- Array may contain negative numbers and duplicates.
- Indices are 0-based.

## Sample
**Input:**

5
3 2 4 6 8
6

**Output:**

1 2

**Explanation:** `nums[1] + nums[2] = 2 + 4 = 6`.

---

## Approaches Implemented

### 1. Brute Force — `brute_force.cpp`
Check every pair `(i, j)` with `i < j` and test if `nums[i] + nums[j] == target`.

| Complexity | Value |
|------------|-------|
| Time       | O(n²) |
| Space      | O(1)  |

**Pros:** Simple, no extra memory.
**Cons:** Too slow for large inputs.

---

### 2. Sorting + Two Pointers — `sort_two_pointers.cpp`
Store `{value, original_index}` pairs, sort by value, then use two pointers 
from both ends:
- If sum == target → output the original indices.
- If sum < target → move left pointer right.
- If sum > target → move right pointer left.

| Complexity | Value      |
|------------|------------|
| Time       | O(n log n) |
| Space      | O(n)       |

**Pros:** Faster than brute force.
**Cons:** Sorting modifies order; must carry original indices. Extra O(n) space.

---

### 3. Hash Map (Optimal) — `hashmap.cpp`
Single pass. For each `nums[i]`, check if `target - nums[i]` is already in 
the map. If yes → print `mp[required]` and `i`. Otherwise, store `nums[i]`.

| Complexity | Value |
|------------|-------|
| Time       | O(n)  |
| Space      | O(n)  |

**Pros:** Fastest possible; interview favorite.
**Cons:** Uses extra memory.

> **Key detail:** We insert into the map *after* checking, so an element is never matched with itself.

---

## Comparison Table

| Approach              | Time       | Space | When to use                        |
|-----------------------|------------|-------|------------------------------------|
| Brute Force           | O(n²)      | O(1)  | Learning / tiny inputs             |
| Sort + Two Pointers   | O(n log n) | O(n)  | When sorted order is also useful   |
| Hash Map              | O(n)       | O(n)  | **Best general solution**          |

---

## Edge Cases Covered
- ✅ Negative numbers
- ✅ Duplicate values
- ✅ Same element used twice → prevented by checking before inserting into the map

## How to Compile & Run
```bash
g++ brute_force.cpp -o brute_force
./brute_force

g++ sort_two_pointers.cpp -o sort_two_pointers
./sort_two_pointers

g++ hashmap.cpp -o hashmap
./hashmap
