class Solution {
public:
    int f(vector<int>& nums, int i, int temp, int target,
          vector<vector<int>>& dp, int sum) {

        if(i == nums.size()){
            if(temp == target) return 1;
            return 0;
        }

        if(dp[i][temp + sum] != -1)
            return dp[i][temp + sum];

        int add = f(nums, i+1, temp+nums[i], target, dp, sum);
        int minus = f(nums, i+1, temp-nums[i], target, dp, sum);

        return dp[i][temp + sum] = add + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target){
        int n = nums.size();

        int sum = 0;
        for(int x : nums) sum += x;

        vector<vector<int>> dp(n, vector<int>(2*sum+1, -1));

        return f(nums, 0, 0, target, dp, sum);
    }
};