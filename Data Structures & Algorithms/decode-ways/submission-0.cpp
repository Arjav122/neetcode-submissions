class Solution {
public:
    int f(string &s, int i, vector<int>& dp) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int one = f(s, i + 1, dp);

        int two = 0;
        if(i + 1 < s.size() && 
           (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            two = f(s, i + 2, dp);
        }

        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return f(s, 0, dp);
    }
};