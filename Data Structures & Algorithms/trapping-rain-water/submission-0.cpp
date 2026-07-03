class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for(int i=0; i<height.size(); i++){
            int left = 0;
            for(int j=i-1; j>=0; j--){
                left = max(left, height[j]);
            }
            int right = 0;
            for(int j=i+1; j<height.size(); j++){
                right = max(right, height[j]);
            }
            int trap = min(left, right) - height[i];
            if(trap>0) ans+=trap;
        }
        return ans;
    }
};
