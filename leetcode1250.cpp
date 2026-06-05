/*
Problem: LeetCode 1250 – Check If It Is a Good Array

Approach:
1. Use Bézout's Identity:
   - An array is good if there exist integer coefficients
     such that their linear combination equals 1.
2. Mathematical Observation:
   - This is possible if and only if the GCD of all
     elements in the array is 1.
3. Compute GCD of all elements:
   - Start with first element.
   - Continuously update GCD with remaining elements.
4. Early Optimization:
   - If GCD becomes 1 at any point,
     immediately return true.
5. Return whether final GCD equals 1.

Key Idea:
- According to Bézout's Identity,
  a linear combination can form 1 iff overall GCD = 1.

Time Complexity: O(N * log(M))
  where M = maximum element in array
Space Complexity: O(1)
*/

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            g = gcd(g, nums[i]);

            if (g == 1)
                return true;
        }
        return g == 1;
    }
};


//According to Bézout's Identity:
// Example 1
// nums = [12, 5, 7, 23]
// gcd(12,5) = 1
// gcd(1,7) = 1
// gcd(1,23) = 1
// Final GCD = 1
// Answer:
// true
