class Solution {
public:
    void f(int n, int oc, int cc, vector<string> &ans, string &temp){
        if(oc+cc == 2*n){
            ans.push_back(temp);
            return;
        }
        if(oc<n){
            temp += "(";
            f(n, oc+1, cc, ans, temp);
            temp.pop_back();
        }
        if(cc<oc){
            temp += ")";
            f(n, oc, cc+1, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        f(n, 0, 0, ans, temp);
        return ans;
    }
};
