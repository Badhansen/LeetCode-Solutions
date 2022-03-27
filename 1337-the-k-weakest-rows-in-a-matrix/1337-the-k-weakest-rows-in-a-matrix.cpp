class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> row;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < m; j++){
                if(mat[i][j]) count++;
            }
            row.push_back({count, i});
        }
        sort(row.begin(), row.end());
        vector<int> ans(k);
        for(int i = 0; i < k; i++) ans[i] = row[i].second;
        return ans;
    }
};