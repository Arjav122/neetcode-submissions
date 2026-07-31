class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int startIdx = 0;
        int tank = 0;
        for(int i=0; i<gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){
                startIdx = i+1;
                tank = 0;
            }
        }
        return (totalGas < totalCost) ? -1 : startIdx;
    }
};
