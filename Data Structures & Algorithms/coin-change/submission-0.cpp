class Solution {
public:
    int f(vector<int>& coins, int i, int amount){
        if(i == 0) {
            if(amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }

        int take = 1e9;
        if(amount >= coins[i]) take = 1 + f(coins, i, amount-coins[i]);
        int notTake = f(coins, i-1, amount);
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(coins, n-1, amount);
        if(ans == 1e9) return -1;
        return ans;
    }
};
