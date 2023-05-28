class Solution {
private:
    
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        map<int, vector<pair<int, int>>, greater<int>> vmap;
        vector<int> rowMax(row, 0);
        vector<int> colMax(col, 0);
        int answer = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                vmap[mat[i][j]].push_back({i, j});
            }
        }
        for (auto &[key, value] : vmap) {
            vector<int> temp(value.size());
            for (int i = 0; i < value.size(); i++) {
                int x = value[i].first, y = value[i].second;
                temp[i] = max(rowMax[x], colMax[y]) + 1;
                answer = max(answer, temp[i]);
            }
            for (int i = 0; i < temp.size(); i++) {
                int x = value[i].first, y = value[i].second;
                rowMax[x] = max(rowMax[x], temp[i]);
                colMax[y] = max(colMax[y], temp[i]);
            }
        }
        return answer;
    }
};