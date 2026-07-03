class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int ans = 0;
        int i = 0, j = n - 1;
        int l = INT_MIN; 
        int r = INT_MIN; 

        while (i <= j) {
            l = max(l, height[i]);
            r = max(r, height[j]); 

            if (l < r) {
                ans += (l - height[i]);
                i++;
            } else {
                ans += (r - height[j]);
                j--;
            }
        }
        return ans;
    }
};