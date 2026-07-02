class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int buy = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>buy){
                int profit = prices[i]-buy;
                maxp = max(maxp, profit); 
            }else{
                buy = prices[i];
            }
        }
        return maxp;
    }
};
