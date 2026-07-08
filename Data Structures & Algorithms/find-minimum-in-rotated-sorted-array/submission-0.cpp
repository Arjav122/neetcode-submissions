class Solution {
public:
    int findMin(vector<int> &nums) {
        int idx = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>0 and nums[i]<nums[i-1]){
                idx = i;
            }
        }
        return nums[idx];
    }
};
