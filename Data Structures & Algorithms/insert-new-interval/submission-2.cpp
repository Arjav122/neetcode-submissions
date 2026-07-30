class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals, vector<vector<int>>& ans){
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(s >= start and s<= end){
                end = max(e, end);
            }else{
                ans.push_back({start,end});
                start = s;
                end = e;
            }
        }
        ans.push_back({start,end});
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        int i=0;
        while(i < intervals.size() && i < intervals.size() && intervals[i][0] < newInterval[0]) i++;
        intervals.insert(intervals.begin()+i, newInterval);
        vector<vector<int>> ans;
        return merge(intervals, ans);
    }
};
