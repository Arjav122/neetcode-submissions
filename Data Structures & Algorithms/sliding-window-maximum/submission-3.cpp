class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0, j=0;
        vector<int> ans;
        while(j<nums.size()){
            if(j-i+1 < k){
                while (!dq.empty() && nums[dq.back()] <= nums[j])dq.pop_back();
                dq.push_back(j);
                j++;
            }else if(j-i+1 == k){
                while(!dq.empty() and nums[dq.back()] < nums[j]) dq.pop_back();
                dq.push_back(j);
                ans.push_back(nums[dq.front()]);
                if(dq.front()==i) dq.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};
