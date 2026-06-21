/*
Problem: LeetCode 2244 – Minimum Rounds to Complete All Tasks

Approach:
1. Count frequency of each task difficulty.
2. For every frequency f:
   - If f == 1:
       → Impossible to form a round
         (each round requires 2 or 3 tasks).
       → Return -1.
3. Otherwise:
   - Minimize number of rounds by using
     as many groups of 3 as possible.
4. Number of rounds needed:
   - (f + 2) / 3
5. Sum rounds for all task difficulties.
6. Return total rounds.

Key Idea:
- Groups of 3 are always optimal.
- Formula (f + 2) / 3 automatically handles
  frequencies that require one group of 2.

Examples:
f = 2 → 1 round
f = 3 → 1 round
f = 4 → 2 rounds (2 + 2)
f = 5 → 2 rounds (3 + 2)
f = 6 → 2 rounds (3 + 3)

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;

        for (int task : tasks) {
            freq[task]++;
        }

        int rounds = 0;

        for (auto& [task, f] : freq) {
            if (f == 1)
                return -1;

            rounds += (f + 2) / 3;
        }

        return rounds;
    }
};
