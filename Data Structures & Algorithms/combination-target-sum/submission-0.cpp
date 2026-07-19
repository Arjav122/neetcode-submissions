class Solution {
public:
    void f(vector<int>& nums, int target, int i, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0 or i==nums.size()){
            return;
        }

        for(int j=i; j<nums.size(); j++){
            temp.push_back(nums[j]);
            f(nums, target-nums[j], j, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(nums, target, 0, ans, temp);
        return ans;
    }
};
