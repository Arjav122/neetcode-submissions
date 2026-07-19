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

        f(nums, i+1, ans, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(nums, 0, ans, temp);
        return ans;
    }
};
