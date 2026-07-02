class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> r(9);
        vector<unordered_set<int>> c(9);
        vector<unordered_set<int>> b(9);
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j]-'0';
                int boxNo = (i/3)*3 + (j/3);
                if(r[i].count(num) || c[j].count(num) || b[boxNo].count(num)) return false;
                r[i].insert(num);
                c[j].insert(num);
                b[boxNo].insert(num);
            }
        }
        return true;
    }
};
