class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            if(i>0 and nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r and nums[l]==nums[l-1]) l++;
                    while(l<r and nums[r]==nums[r+1]) r--;
                }else if(nums[l]+nums[r]>target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};
