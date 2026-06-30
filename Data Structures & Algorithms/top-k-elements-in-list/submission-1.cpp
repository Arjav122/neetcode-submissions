class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x:nums){
            mp[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> minHeap;
        for(auto it:mp){
            if(minHeap.size()<k) minHeap.push({it.second, it.first});
            else if(minHeap.top().first < it.second){
                minHeap.pop();
                minHeap.push({it.second, it.first});
            }
        }
        vector<int> ans;
        while(k--){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
