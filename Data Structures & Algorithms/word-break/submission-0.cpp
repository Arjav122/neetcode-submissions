class Solution {
public:
    bool f(string &s, int i, unordered_set<string> &st, vector<int> &dp) {
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];

        for(int j = i; j < s.size(); j++) {
            string word = s.substr(i, j-i+1);
            if(st.find(word) != st.end()) {
                if(f(s, j+1, st, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return f(s, 0, st, dp);
    }
};