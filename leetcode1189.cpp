/*
Problem: LeetCode 1189 – Maximum Number of Balloons

Approach:
1. Count the frequency of every character
   in the given string.
2. To form one "balloon", we need:
   - 'b' → 1 time
   - 'a' → 1 time
   - 'l' → 2 times
   - 'o' → 2 times
   - 'n' → 1 time
3. Compute how many complete occurrences
   of each required character are available:
   - freq['b']
   - freq['a']
   - freq['l'] / 2
   - freq['o'] / 2
   - freq['n']
4. The limiting character determines the
   maximum number of "balloon" words that
   can be formed.
5. Return the minimum among these values.

Key Idea:
- Characters 'l' and 'o' are required twice,
  so their frequencies must be divided by 2.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for(char ch : text) {
            freq[ch - 'a']++;
        }

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};
