class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int x = nums[0], maxSoFar = x;
        for(int i=1; i<nums.size(); i++){
            x = max(x + nums[i], nums[i]);
            maxSoFar = max(x, maxSoFar);
        }   
        return maxSoFar;
    }
};
