class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int len = gas.size();
        int tank = 0;
        int start = 0;
        
        for(int i = 0; i < len; i++){
            totalCost += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        
        return totalCost < 0 ? -1 : start;
    }
};