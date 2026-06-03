/*
Problem: LeetCode 1969 – Minimum Non-Zero Product of the Array Elements

Approach:
1. Mathematical Observation:
   - Numbers range from 1 to (2^p - 1).
   - Minimum non-zero product is achieved by:
       (2^p - 2) repeated (2^(p-1) - 1) times
       and one occurrence of (2^p - 1).
2. Formula:
   - Answer =
     ((2^p - 2)^(2^(p-1)-1) * (2^p - 1)) mod M
3. Use Binary Exponentiation:
   - Efficiently compute large powers modulo M.
4. Compute:
   - maxNum = 2^p - 1
   - second = 2^p - 2
   - exp = 2^(p-1) - 1
5. Return:
   - power(second, exp) * maxNum mod M

Key Idea:
- Mathematical pattern reduces the problem
  to a single modular exponentiation.

Time Complexity: O(log(2^(p-1))) ≈ O(p)
Space Complexity: O(1)
*/

class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long base, long long exp) {
        base %= MOD;
        long long ans = 1;
        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

    int minNonZeroProduct(int p) {
        long long maxNum = (1LL << p) - 1;          // 2^p - 1
        long long second = maxNum - 1;             // 2^p - 2
        long long exp = (1LL << (p - 1)) - 1;      // 2^(p-1) - 1

        long long part1 = power(second, exp);
        long long part2 = maxNum % MOD;

        return (part1 * part2) % MOD;
    }
};
