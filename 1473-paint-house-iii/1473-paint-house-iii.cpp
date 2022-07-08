class Solution {
private:
    int cache[105][105][25];
    int houseCount, totalColor;
    const int maxCost = INT_MAX / 2;
public:
    int dfs(int hID, int neighborCount, int color, vector<int>& houses, vector<vector<int>>& cost){
        if(hID == houseCount){
            return neighborCount == 0 ? 0 : maxCost;
        }
        if(neighborCount < 0){
            return maxCost;
        }
        int &ret = cache[hID][neighborCount][color];
        if(ret != -1){
            return ret;
        }
        ret = maxCost;
        if(houses[hID]){
            int newNeighbourCount = neighborCount - (houses[hID] != color); 
            ret = min(ret, dfs(hID + 1, newNeighbourCount, houses[hID], houses, cost));
        }
        else{
            for(int c = 1; c <= totalColor; c++){
                int newNeighbourCount = neighborCount - (c != color);
                ret = min(ret, cost[hID][c - 1] + dfs(hID + 1, newNeighbourCount, c, houses, cost));
            }
        }
        return ret;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        houseCount = m, totalColor = n;
        memset(cache, -1, sizeof cache);
        int result = dfs(0, target, 0, houses, cost);
        return result == maxCost ? -1 : result;
    }
};

// Time: O(Total House * Target Neighbor * Total Color ^ 2)
// Space: (Total House * Target Neighbor * Total Color)