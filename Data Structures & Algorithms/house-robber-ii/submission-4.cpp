class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        dp1[0] = nums[0];
        for(int i=1; i<n-1; i++){
            int rob = nums[i] + (i >= 2 ? dp1[i-2] : 0);
            int notRob = dp1[i-1];
            dp1[i] = max(rob, notRob);
        }

        dp2[1] = nums[1];
        for(int i=2; i<n; i++){
            int rob = nums[i] + dp2[i-2];
            int notRob = dp2[i-1];
            dp2[i] = max(rob, notRob);
        }

        return max(dp1[n-2], dp2[n-1]);
    }
};