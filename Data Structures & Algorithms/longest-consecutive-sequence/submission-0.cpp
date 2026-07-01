class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int i=0, ans=1;
        while(i<nums.size()){
            int temp=1;
            while(i+1 < nums.size()){
                if (nums[i] == nums[i + 1]){
                    i++;               
                }
                else if (nums[i] + 1 == nums[i + 1]){
                    temp++;
                    i++;
                }
                else{
                    break;
                }
            }
            ans = max(ans, temp);
            i++;
        }  
        return ans;    
    }
};
