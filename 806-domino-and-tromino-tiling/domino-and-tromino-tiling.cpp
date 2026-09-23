class Solution {
public:
    int numTilings(int n) {
        const long long MOD = 1000000007;

        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        long long dp0 = 1;
        long long dp1 = 1;
        long long dp2 = 2;

        for (int i = 3; i <= n; i++) {
            long long current = (2 * dp2 + dp0) % MOD;

            dp0 = dp1;
            dp1 = dp2;
            dp2 = current;
        }

        return dp2;
    }
};