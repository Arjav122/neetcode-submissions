class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, vector<int>>> maxHeap;
        vector<vector<int>> ans;
        for(auto &it : points){
            int x = it[0];
            int y = it[1];
            float dist = sqrt(pow(x, 2) + pow(y, 2));
            maxHeap.push({dist, {x, y}});
            if(maxHeap.size()>k) maxHeap.pop();
        }
        while(k--){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
