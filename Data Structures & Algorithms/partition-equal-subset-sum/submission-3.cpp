class Solution {
public:
    bool f(vector<int> &nums, int i, int target,  vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i<0) return false;
        if(dp[i][target] != -1) return dp[i][target];

        bool take = false;
        if(nums[i] <= target) take = f(nums, i-1, target-nums[i], dp);
        bool notTake = f(nums, i-1, target, dp);
        return dp[i][target] = take or notTake;
    }
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int totalSum = 0;
        for(int x:nums) totalSum += x;
        if(totalSum % 2 != 0) return false;
        int target = totalSum/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(nums, n-1, target, dp);
    }
};
