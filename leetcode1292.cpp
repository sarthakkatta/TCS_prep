/*
Problem: LeetCode 1292 – Maximum Side Length of a Square with Sum Less than or Equal to Threshold

Approach:
1. Build a 2D Prefix Sum matrix:
   - pref[i][j] stores sum of elements in rectangle
     from (0,0) to (i-1,j-1).
2. Use Binary Search on side length:
   - low = 0
   - high = min(rows, cols)
3. For a given side length len:
   - Check all possible len × len squares.
4. Compute square sum using prefix sums:
   sum = pref[i][j]
         - pref[i-len][j]
         - pref[i][j-len]
         + pref[i-len][j-len]
5. If any square has:
   - sum <= threshold
     → length is valid.
6. Binary Search:
   - Valid → try larger length.
   - Invalid → try smaller length.
7. Return maximum valid side length.

Key Idea:
- Prefix sums allow O(1) square-sum queries.
- Binary search finds the largest valid side length efficiently.

Time Complexity: O(N × M × log(min(N,M)))
Space Complexity: O(N × M)
*/

class Solution {
public:
    bool check(vector<vector<int>>& pref, vector<vector<int>>& mat, int len, int threshold){
        int n = mat.size();
        int m = mat[0].size();

        for(int i = len; i <= n; i++){
            for(int j = len; j <= m; j++){
                int sum = pref[i][j] - pref[i - len][j]
                        - pref[i][j - len]
                        + pref[i - len][j - len];

                if(sum <= threshold){
                    return true;
                }
            }
        }

        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pref[i][j] = mat[i-1][j-1]
                           + pref[i-1][j]
                           + pref[i][j-1]
                           - pref[i-1][j-1];
            }
        }

        int low = 0;
        int high = min(n, m);
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(pref, mat, mid, threshold)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }
};
