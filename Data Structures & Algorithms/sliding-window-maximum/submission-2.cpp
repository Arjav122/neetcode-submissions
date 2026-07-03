class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int ,int>> maxheap;
        vector<int> ans;
        int i=0, j=0;
        while(j<nums.size()){
            if(j-i+1 < k){
                maxheap.push({nums[j], j});
                j++;
            }else if(j-i+1 == k){
                maxheap.push({nums[j], j});
                while (!maxheap.empty() && maxheap.top().second < i) maxheap.pop();
                ans.push_back(maxheap.top().first);
                i++;
                j++;
            }
        }
        return ans;
    }
};
