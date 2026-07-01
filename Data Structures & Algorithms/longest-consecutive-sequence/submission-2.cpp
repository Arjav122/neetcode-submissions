class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int ans=1;
        for(int x:st){
            int cnt=1;
            if(!st.count(x-1)){
                while(st.count(x+1)){
                    cnt++;
                    x++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
