class Solution {
private:
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
public:
    bool isValid(vector<vector<int>>& heights, int mid){
        int row = heights.size(), col = heights[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        queue<pair<int, int>> que;
        que.push({0, 0});
        visit[0][0] = true;
        while(!que.empty()){
            int u = que.front().first;
            int v = que.front().second;
            que.pop();
            if(u == row - 1 && v == col - 1){
                return true;
            }
            for(int i = 0; i < 4; i++){
                int nu = dirX[i] + u;
                int nv = dirY[i] + v;
                if(nu >= 0 && nu < row && nv >= 0 && nv < col && visit[nu][nv] == false){
                    int weight = abs(heights[nu][nv] - heights[u][v]);
                    if(weight > mid){
                        continue;
                    }
                    visit[nu][nv] = true;
                    que.push({nu, nv});
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0, high = INT_MAX, best = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isValid(heights, mid)){
                high = mid - 1;
                best = min(best, mid);
            }
            else{
                low = mid + 1;
            }
        }
        return best;
    }
};