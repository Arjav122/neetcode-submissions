class Solution {
public:
    void helper(const string &digits, vector<string> &ans,
                string &temp, unordered_map<char,string> &mp, int i){

        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[i]];

        for(char ch : letters){
            temp.push_back(ch);
            helper(digits, ans, temp, mp, i+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        unordered_map<char,string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        vector<string> ans;
        string temp;

        helper(digits, ans, temp, mp, 0);

        return ans;
    }
};