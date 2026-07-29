class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> ans;
        // sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        //     return a[0] < b[0];
        // });

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1; i< intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(s>= start && s<=end) {
                end = max(e, end);
            }

            else {
                ans.push_back({start,end});
                start = s;
                end = e;
            }
        }

        ans.push_back({start,end});
        return ans;
    }
};
