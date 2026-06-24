class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memo;
    double helper(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (memo[a][b] != 0) return memo[a][b];

        memo[a][b] = 0.25 * (
            helper(a - 100, b) +
            helper(a - 75, b - 25) +
            helper(a - 50, b - 50) +
            helper(a - 25, b - 75)
        );
        return memo[a][b];
    }
    double soupServings(int N) {
        if (N >= 4800) return 1.0;
        return helper(N, N);
    }
};
