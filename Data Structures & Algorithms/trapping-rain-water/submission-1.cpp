class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        vector<int> left(n);
        int lmax = height[0];
        for(int i=1; i<n; i++){
            left[i] = lmax;
            lmax = max(lmax, height[i]);
        }

        vector<int> right(n);
        int rmax = height[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = rmax;
            rmax = max(rmax, height[i]);
        }

        for(int i=0; i<n; i++){
            int trap = min(left[i], right[i]) - height[i];
            if(trap>0) ans+=trap;
        }
        return ans;
    }
};
