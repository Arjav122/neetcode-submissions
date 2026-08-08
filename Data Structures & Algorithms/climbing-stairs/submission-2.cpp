class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int idx = 1; idx <= n; idx++) {
            dp[idx] += dp[idx - 1];
            if (idx >= 2) dp[idx] += dp[idx - 2];
        }
        return dp[n];
    }
};