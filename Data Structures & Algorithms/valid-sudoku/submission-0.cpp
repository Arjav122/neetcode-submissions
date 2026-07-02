class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9];
        unordered_set<int> col[9];
        unordered_set<int> boxes[9];

        for(int i=0; i<board.size(); i++){
            for(int j=0; j< board[0].size(); j++){
                if(board[i][j]=='.') continue;
                char num = board[i][j];
                int box_no = (i / 3) * 3 + (j / 3);
                if(row[i].count(num) || col[j].count(num) || boxes[box_no].count(num)) return false;
                row[i].insert(num);
                col[j].insert(num);
                boxes[box_no].insert(num);
            }
        }
        return true;
    }
};
