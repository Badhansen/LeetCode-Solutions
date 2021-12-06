class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0, oddCount = 0;
        for(auto &p : position){
            if(p & 1) oddCount++;
            else evenCount++;
        }
        return min(evenCount, oddCount);
    }
};