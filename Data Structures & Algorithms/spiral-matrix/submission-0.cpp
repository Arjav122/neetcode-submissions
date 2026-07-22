class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ans;
        if (matrix.empty()) return ans;
        int sr=0, er=matrix.size()-1, sc=0, ec=matrix[0].size()-1;
        
        while(sr<=er and sc<=ec){
            for(int j=sc; j<=ec; j++){
                ans.push_back(matrix[sr][j]);
            }
            sr++;

            for(int i=sr; i<=er; i++){
                ans.push_back(matrix[i][ec]);
            }
            ec--;

            if(sr<=er){
                for(int j=ec; j>=sc; j--){
                    ans.push_back(matrix[er][j]);
                }
                er--;
            }

            if(sc<=ec){
                for(int i=er; i>=sr; i--){
                ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
        return ans;
    }
};
