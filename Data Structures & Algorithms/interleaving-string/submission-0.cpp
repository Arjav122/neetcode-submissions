class Solution {
public:
    bool f(string &s1, string &s2, string &s3,
           int i, int j, vector<vector<int>> &dp) {

        int k = i + j;

        // All characters of s3 are used
        if(k == s3.size())
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        bool takeS1 = false;
        bool takeS2 = false;

        // Take character from s1
        if(i < s1.size() && s1[i] == s3[k]) {
            takeS1 = f(s1, s2, s3, i+1, j, dp);
        }

        // Take character from s2
        if(j < s2.size() && s2[j] == s3[k]) {
            takeS2 = f(s1, s2, s3, i, j+1, dp);
        }

        return dp[i][j] = takeS1 || takeS2;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        return f(s1, s2, s3, 0, 0, dp);
    }
};