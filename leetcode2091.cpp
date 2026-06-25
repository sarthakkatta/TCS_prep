/*
Problem: LeetCode 2091 – Removing Minimum and Maximum From Array

Approach:
1. Find:
   - Index of minimum element.
   - Index of maximum element.
2. Let:
   - left  = min(minIdx, maxIdx)
   - right = max(minIdx, maxIdx)
3. Consider three possible ways:
   a) Remove from front only:
      - Need to delete up to right index.
      - Operations = right + 1
   b) Remove from back only:
      - Need to delete from left index to end.
      - Operations = n - left
   c) Remove from both ends:
      - Remove left part from front.
      - Remove right part from back.
      - Operations =
          (left + 1) + (n - right)
4. Return the minimum among all three options.

Key Idea:
- Minimum and maximum can be removed
  either from the front, back, or a combination
  of both ends.
- Check all possible strategies and take the best.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minidx = 0;
        int maxidx = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < nums[minidx])
                minidx = i;

            if(nums[i] > nums[maxidx])
                maxidx = i;
        }

        int left = min(minidx, maxidx);
        int right = max(minidx, maxidx);

        int front = right + 1;
        int back = n - left;
        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};
