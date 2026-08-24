class Solution {
public:
    int f(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];

        int take = 0;
        if(prev == nums.size() || nums[i] > nums[prev]) {
            take = 1 + f(nums, i + 1, i, dp);
        }
        int notTake = f(nums, i + 1, prev, dp);
        return dp[i][prev] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(nums, 0, n, dp);
    }
};
