/*
Problem: LeetCode 1286 – Iterator for Combination

Approach:
1. Generate all possible combinations of length n
   using Backtracking.
2. backtrack():
   - If current combination length becomes n:
       → Store it in comb vector.
       → Return.
3. Otherwise:
   - Try every character from current index onward.
   - Include character.
   - Recurse for next position.
   - Backtrack by removing the character.
4. Constructor:
   - Generate all combinations.
   - Initialize iterator to the first combination.
5. next():
   - Return current combination.
   - Move iterator to next position.
6. hasNext():
   - Check whether iterator has reached the end.

Key Idea:
- Precompute all valid combinations once.
- Then next() and hasNext() become simple iterator operations.

Time Complexity:
- Constructor:
    O(C(n, k) * k)
  (generate all combinations)
- next():
    O(1)
- hasNext():
    O(1)

Space Complexity:
- O(C(n, k) * k)
  (stores all combinations)
*/

class CombinationIterator {
    string s;
    int n;

    vector<string> comb;
    vector<string>::iterator cur;

    void backtrack(string& s, int n, string& combination, int i) {
        if(size(combination) == n) {
            comb.push_back(combination);
            return;
        }

        for(int j = i; j < size(s); j++) {
            combination += s[j];

            backtrack(s, n, combination, j + 1);

            combination.pop_back();
        }
    }

public:
    CombinationIterator(string& s, int n) : s(s), n(n) {
        string combination{""};

        backtrack(s, n, combination, 0);

        cur = begin(comb);
    }

    string next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != end(comb);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj =
 * new CombinationIterator(characters, combinationLength);
 *
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
