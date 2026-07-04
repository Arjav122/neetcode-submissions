class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nsr(n);
        stack<int> st1;
        for(int i=n-1; i>=0; i--){
            while(!st1.empty() && heights[st1.top()] >= heights[i]) st1.pop();
            if(st1.empty()){
                nsr[i] = n;
            }else{
                nsr[i] = st1.top();
            }
            st1.push(i);
        }

        vector<int> nsl(n);
        stack<int> st2;
        for(int i=0; i<n; i++){
            while(!st2.empty() && heights[st2.top()] >= heights[i]) st2.pop();
            if(st2.empty()){
                nsl[i] = -1;
            }else{
                nsl[i] = st2.top();
            }
            st2.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int width = nsr[i] - nsl[i] - 1;
            int height = heights[i];
            int area = height*width;
            ans = max(ans, area);
        }
        return ans;
    }
};
