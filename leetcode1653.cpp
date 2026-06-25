/*
Problem: LeetCode 1653 – Minimum Deletions to Make String Balanced

Approach:
1. Traverse the string from left to right.
2. Maintain:
   - bBefore  → number of unmatched 'b' characters seen so far.
   - deletion → minimum deletions performed.
3. For each character:
   - If character is 'b':
       → Increase bBefore.
   - If character is 'a':
       → An inversion "ba" exists.
4. Two choices for current 'a':
   - Delete current 'a'
   - Delete one previous 'b'
5. Greedy Choice:
   - Delete one previous 'b'
       → bBefore--
       → deletion++
6. Continue until end of string.
7. Return total deletions.

Key Idea:
- A balanced string must have all 'a's before all 'b's.
- Every occurrence of "ba" creates a conflict.
- Track and resolve conflicts greedily.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int bBefore = 0;
        int deletion = 0;

        for(auto c : s) {
            if(c == 'b') {
                bBefore += 1;
            }
            else if(bBefore > 0) {
                bBefore -= 1;
                deletion += 1;
            }
        }

        return deletion;
    }
};
