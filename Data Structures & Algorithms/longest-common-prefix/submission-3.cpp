class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string ans = "";
        string s1 = strs[0], s2 = strs[n-1];
        int i=0;
        while(i<s1.size() && s1[i]==s2[i]){
            ans += s1[i];
            i++;
        }
        return ans;
    }
};