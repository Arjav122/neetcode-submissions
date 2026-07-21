class Solution {
public:
    bool f(vector<vector<char>>& board, string& word, int i, int j, int idx){
        if(idx == word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool left = f(board, word, i, j-1, idx+1);
        bool right = f(board, word, i, j+1, idx+1);
        bool up = f(board, word, i-1, j, idx+1);
        bool down = f(board, word, i+1, j, idx+1);

        board[i][j] = temp;

        return left or right or up or down;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(f(board, word, i, j, 0)) return true;
                }   
            }
        }
        return false;
    }
};
