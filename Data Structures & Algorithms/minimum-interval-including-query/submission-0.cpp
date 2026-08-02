class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans(queries.size(), -1);
        for(int i=0; i<queries.size(); i++){
            int minVal = INT_MAX;
            for(int j=0; j<intervals.size(); j++){
                int a = intervals[j][0];
                int b = intervals[j][1];
                if(queries[i] >= a and queries[i]<= b){
                    minVal = min(minVal, b-a+1);
                }
            }
            if(minVal != INT_MAX) ans[i] = minVal;
        }
        return ans;
    }
};
