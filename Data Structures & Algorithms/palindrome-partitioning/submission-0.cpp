class Solution {
public:
    bool palindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }   
        return true;
    }

    void f(string s, int i, vector<vector<string>> &ans, vector<string> &temp){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int j=i; j<s.size(); j++){
            if(palindrome(s, i, j)){
                temp.push_back(s.substr(i, j-i+1));
                f(s, j+1, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(s, 0, ans, temp);
        return ans;
    }
};
