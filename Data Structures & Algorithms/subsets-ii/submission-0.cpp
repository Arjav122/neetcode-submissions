class Solution {
public:
    void f(vector<int>& nums, int i, vector<vector<int>> &ans, vector<int> &temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        f(nums, i+1, ans, temp);
        temp.pop_back();

        while(i+1<nums.size() and nums[i]==nums[i+1])i++;

        f(nums, i+1, ans, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(nums, 0, ans, temp);
        return ans;
    }
};
