class Solution {
public:

    bool isValid(vector<string>& board, int r, int j){
        for(int i=r-1; i>=0; i--){
            if(board[i][j] == 'Q') return false;
        }

        int step = 1;
        for(int i=r-1; i>=0 and j-step >= 0; i--){
            if(board[i][j-step++] == 'Q') return false;
        }

        step=1;
        for(int i=r-1; i>=0 and j+step < board.size(); i--){
            if(board[i][j+step++] == 'Q') return false;
        }
        return true;
    }

    void f(int n, int r, vector<string>& board, vector<vector<string>>& ans){
        if(r==n){
            ans.push_back(board);
            return;
        }
        
        for(int j=0; j<n; j++){
            if(isValid(board, r, j)){
                board[r][j]='Q';
                f(n, r+1, board, ans);
                board[r][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        f(n, 0, board, ans);
        return ans;
    }
};
