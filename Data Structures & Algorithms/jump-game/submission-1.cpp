class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx=0;
        for(int i=0; i<nums.size(); i++){
            if(i <= maxIdx and i+nums[i]>=maxIdx){
                maxIdx = max(maxIdx, i+nums[i]);
            }
        }
        return maxIdx >= nums.size()-1;
    }
};
