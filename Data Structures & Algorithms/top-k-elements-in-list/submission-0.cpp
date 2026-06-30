class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x:nums){
            mp[x]++;
        }
        priority_queue<pair<int, int>> maxHeap;
        for(auto it:mp){
            maxHeap.push({it.second, it.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
