/*
Problem: LeetCode 2256 – Minimum Average Difference

Approach:
1. Compute total sum of the array.
2. Traverse the array while maintaining:
   - leftSum  → sum of elements from 0 to i
   - rightSum → total - leftSum
3. For each index i:
   - leftAvg  = leftSum / (i + 1)
   - rightAvg = rightSum / (n - i - 1)
   - If i is the last index:
       rightAvg = 0
4. Calculate:
   - diff = |leftAvg - rightAvg|
5. Track:
   - Minimum difference found so far.
   - Corresponding index.
6. Return the index having minimum average difference.

Key Idea:
- Prefix sums allow left and right averages
  to be computed efficiently in one pass.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total = 0;

        for(int x : nums)
            total += x;

        long long leftSum = 0;
        long long minDiff = LLONG_MAX;
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            leftSum += nums[i];

            long long rightSum = total - leftSum;

            long long leftAvg = leftSum / (i + 1);

            long long rightAvg =
                (i == n - 1) ? 0 : rightSum / (n - i - 1);

            long long diff = llabs(leftAvg - rightAvg);

            if(diff < minDiff) {
                minDiff = diff;
                ans = i;
            }
        }

        return ans;
    }
};
