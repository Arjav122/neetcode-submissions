class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        int ans = -1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }else if(nums[mid] > target){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};
