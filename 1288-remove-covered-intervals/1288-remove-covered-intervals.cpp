class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        int ans = 0;
        vector<bool> vis(len, false);
        for(int i = 0; i < len; i++){
            if(vis[i]) continue;
            for(int j = 0; j < len; j++){
                if(i != j && vis[i] == false && intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                    vis[i] = true;
                    ans++;
                }
            }
        }
        return len - ans;
    }
};