class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i=0; i<strs.size(); i++){
            encoded += to_string(strs[i].size()) + '&' + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) {
            string len = "";
            while (s[i] != '&'){
                len += s[i];
                i++;
            }
            int length = stoi(len);
            i++;
            string word = s.substr(i, length);
            decoded.push_back(word);
            i += length;
        }
        return decoded;
    }
};
