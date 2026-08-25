class Solution {
public:
    int f(vector<int>& coins, int i, int amount, vector<vector<int>>& dp){
        if(i == 0) {
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 0;
        if(amount >= coins[i]) take = f(coins, i, amount-coins[i], dp);
        int notTake = f(coins, i-1, amount, dp);
        return dp[i][amount] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(coins, n-1, amount, dp);
    }
};
