class Solution {
public:
    int f(vector<int> &nums, int i, int end, vector<int>& dp){
        if(i<end) return 0;
        if(dp[i] != -1) return dp[i];

        int rob = nums[i] + f(nums, i-2, end, dp);
        int notRob = 0 + f(nums, i-1, end, dp);
        return dp[i] = max(rob, notRob);
    }

    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int a = f(nums, n-1, 1, dp1);
        int b = f(nums, n-2, 0, dp2);
        return max(a, b);
    }
};
