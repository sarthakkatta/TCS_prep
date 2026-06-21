/*
Problem: LeetCode 1299 – Replace Elements with Greatest Element on Right Side

Approach:
1. Traverse the array from right to left.
2. Maintain:
   - max_element → greatest element seen so far on the right.
3. For each index:
   - Store current value.
   - Replace current element with max_element.
   - Update max_element using the stored value.
4. Initialize:
   - max_element = -1
   - Last element always becomes -1.
5. Return the modified array.

Key Idea:
- While moving from right to left,
  we always know the maximum element present
  on the right side of the current index.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        int max_element = -1;

        for (int i = n - 1; i >= 0; i--) {
            int current_val = arr[i];

            arr[i] = max_element;

            max_element = max(max_element, current_val);
        }

        return arr;
    }
};
