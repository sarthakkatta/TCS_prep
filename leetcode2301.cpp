/*
Problem: LeetCode 2301 – Match Substring After Replacement

Approach:
1. Create a replacement lookup table:
   - canReplace[a][b] = true
   - Means character 'a' in sub can be replaced by 'b' in s.
2. Traverse every possible starting position in s:
   - Window size = sub.length().
3. For each position:
   - Compare sub with current substring.
4. Characters match if:
   - They are equal, OR
   - Replacement mapping exists.
5. If every character matches:
   - Return true.
6. If no valid substring exists:
   - Return false.

Key Idea:
- Precompute allowed replacements for O(1) matching checks.

Time Complexity: O((N - M + 1) × M)
Space Complexity: O(128 × 128)
*/

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        vector<vector<bool>> canReplace(128, vector<bool>(128, false));

        for (auto &m : mappings) {
            canReplace[m[0]][m[1]] = true;
        }

        int n = s.size();
        int m = sub.size();

        for (int i = 0; i <= n - m; i++) {
            bool ok = true;

            for (int j = 0; j < m; j++) {
                if (sub[j] == s[i + j]) continue;

                if (!canReplace[sub[j]][s[i + j]]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};
