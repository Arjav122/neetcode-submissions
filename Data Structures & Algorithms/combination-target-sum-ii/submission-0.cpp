class Solution {
public:
    void f(vector<int>& candidates, int target, int i, vector<vector<int>> &ans, vector<int> &temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(i == candidates.size() or target<0) return;

        for(int j=i; j<candidates.size(); j++){
            temp.push_back(candidates[j]);
            f(candidates, target-candidates[j], j+1, ans, temp);
            temp.pop_back();

            while(j+1 < candidates.size() and candidates[j] == candidates[j+1]) j++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates, target, 0, ans, temp);
        return ans;
    }
};
