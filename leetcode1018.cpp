/*
Problem: LeetCode 1018 – Binary Prefix Divisible By 5

Approach:
1. Maintain remainder of the current binary number modulo 5.
2. Traverse the binary array:
   - Append current bit:
       rem = (rem * 2 + bit) % 5
3. Check divisibility:
   - If rem == 0
       → current binary prefix is divisible by 5.
   - Otherwise not divisible.
4. Store result in answer array.
5. Return final boolean array.

Key Idea:
- Only the remainder modulo 5 is needed.
- Avoids constructing very large binary numbers.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int rem = 0;

        for(int i : nums){
            rem = (rem * 2 + i) % 5;
            ans.push_back(rem == 0);
        }

        return ans;
    }
};
