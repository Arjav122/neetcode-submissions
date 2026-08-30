class Solution {
public:
    int f(vector<vector<int>>& matrix, int i, int j, int prev,
          vector<vector<int>>& dp) {

        int n = matrix.size();
        int m = matrix[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(matrix[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int up = f(matrix, i-1, j, matrix[i][j], dp);
        int down = f(matrix, i+1, j, matrix[i][j], dp);
        int left = f(matrix, i, j-1, matrix[i][j], dp);
        int right = f(matrix, i, j+1, matrix[i][j], dp);

        return dp[i][j] = 1 + max({up, down, left, right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, f(matrix, i, j, INT_MIN, dp));
            }
        }
        return ans;
    }
};