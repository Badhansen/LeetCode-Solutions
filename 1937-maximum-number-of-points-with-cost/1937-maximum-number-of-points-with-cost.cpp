/*
[[1,2,3],[1,5,1],[3,1,1]]
        0 1 2
dp[i - 1] = [d0, d1, d2, d3, d4, |, |, |, |, |]
dp[  i  ] = [ |   |   |   |   |  |  |, |  |, |]
                              j
                        j - 1
dp[i][j] =     max(d0 - 4, d1 - 3, d2 - 2, d3 - 1, d4)
dp[i][j - 1] = max(d0 - 3, d1 - 2, d2 - 1, d3)
d[i][j] = dp[i][j - 1] - 1, dp[i][j]
*/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());
        for(int i = 1; i < n; i++){
            vector<long long>left(m), right(m);
            for(int k = 0; k < m; k++){
                if(k == 0) left[k] = dp[k];
                else left[k] = max(left[k - 1] - 1, dp[k]);
            }
            for(int k = m - 1; k >= 0; k--){
                if(k == m - 1) right[k] = dp[k];
                else right[k] = max(right[k + 1] - 1, dp[k]);
            }
            for(int j = 0; j < m; j++){
                dp[j] = max(left[j], right[j]) + points[i][j];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// Time: O(N * M)
// Space: O(N ^ M)

/*
class Solution {
private:
    vector<vector<long long>> dp;
public:
    long long solve(int r, int c, vector<vector<int>>& points){
        if(r >= points.size()) return 0;
        long long &ret = dp[r][c];
        
        if(ret != -1) return ret;
        
        for(int i = 0; i < points[0].size(); i++){
            ret = max(ret, points[r][i] + solve(r + 1, i, points) - abs(i - c));    
        }
        return ret;
    }
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        dp.resize(n + 1, vector<long long>(m + 1, -1));
        long long ans = 0;
        for(int c = 0; c < points[0].size(); c++){
            ans = max(ans, solve(0, c, points));
        }
        return ans;
    }
};

// Time: O(N * M * M)
// Space: N(N ^ 2)

*/
