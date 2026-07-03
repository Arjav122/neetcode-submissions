class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> mp;

        for (char ch : t)
            mp[ch]++;

        int required = t.size();
        int i = 0, j = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (j < s.size()) {

            if (mp[s[j]] > 0)
                required--;

            mp[s[j]]--;

            while (required == 0) {

                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;

                if (mp[s[i]] > 0)
                    required++;

                i++;
            }

            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};