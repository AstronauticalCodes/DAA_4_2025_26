## Minimum Sum Partition

### Algorithm

1. Compute the total sum of all elements:
   totalSum = sum(arr)

2. Create a DP array:
- `dp[0 … totalSum]` initialized to `false`
- `dp[0] = true` (subset with sum 0 is always possible)

3. Fill the DP array (0/1 Knapsack approach):
- For each element `num` in the array:
  - Traverse from `totalSum` down to `num`:
    ```
    dp[j] = dp[j] OR dp[j - num]
    ```

4. Find the minimum difference:
- Iterate `s1` from `0` to `totalSum / 2`
- If `dp[s1] == true`:
  ```
  s2 = totalSum - s1
  diff = |s2 - s1|
  ```
- Track the minimum difference

5. Return the minimum difference

---

### Key Idea

- Divide the array into two subsets such that their sums are as close as possible.
- Equivalent to finding a subset with sum closest to `totalSum / 2`.

---

### Time Complexity

- DP computation: `O(n × totalSum)`
- Final iteration: `O(totalSum)`
- **Overall:** `O(n × totalSum)`

---

### Space Complexity

- Using optimized 1D DP: `O(totalSum)`

---

### Notes

- This is a variation of the **Subset Sum / 0-1 Knapsack problem**.
- Only half of the sum range (`totalSum / 2`) needs to be checked due to symmetry.
- Space can be reduced from `O(n × totalSum)` to `O(totalSum)` using 1D DP.   