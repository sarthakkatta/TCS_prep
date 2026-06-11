/*
Problem: LeetCode 807 – Max Increase to Keep City Skyline

Approach:
1. Find maximum height in each row:
   - rowMax[i] stores tallest building in row i.
2. Find maximum height in each column:
   - colMax[j] stores tallest building in column j.
3. For every building:
   - Maximum allowed height =
       min(rowMax[i], colMax[j])
   - Increase possible =
       allowed height - current height
4. Add all possible increases.
5. Return total increase.

Key Idea:
- A building can only grow until it reaches
  the smaller of its row skyline and column skyline,
  otherwise the skyline changes.

Time Complexity: O(N²)
Space Complexity: O(N)
*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> rowMax(n, 0);
        vector<int> colMax(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }

        return ans;
    }
};
