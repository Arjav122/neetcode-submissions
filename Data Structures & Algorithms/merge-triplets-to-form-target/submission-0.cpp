class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;
        for(auto it:triplets){
            if(it[0]<=target[0] and it[1]<=target[1] and it[2]<=target[2]){
                if(it[0] == target[0]) a = true;
                if(it[1] == target[1]) b = true;
                if(it[2] == target[2]) c = true;
            }
        }
        return a && b && c;
    }
};
