/*
Problem: LeetCode 1544 – Make The String Great

Approach:
1. Use a string as a stack.
2. Traverse each character in the input string.
3. For current character:
   - If stack is not empty and
     absolute difference between current character
     and stack top is 32:
       → They are same letters with opposite cases
         (e.g., 'a' and 'A').
       → Remove top character.
   - Otherwise:
       → Push current character into stack.
4. After processing all characters:
   - Remaining string is the answer.
5. Return the resulting string.

Key Idea:
- ASCII difference between lowercase and uppercase
  versions of the same letter is 32.
- Adjacent bad pairs cancel each other out.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    string makeGood(string s) {
        string st;

        for(char c : s){
            if(!st.empty() && abs(st.back() - c) == 32){
                st.pop_back();
            }else{
                st.push_back(c);
            }
        }

        return st;
    }
};
