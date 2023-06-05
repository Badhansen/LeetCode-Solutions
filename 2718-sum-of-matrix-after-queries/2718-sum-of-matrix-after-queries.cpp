class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum = 0;
        unordered_map<int, int> rows, cols;
        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0], id = queries[i][1], val = queries[i][2];
            if (type) {
                if (!cols.count(id)) {
                    cols[id] = id;
                    sum += (n - rows.size()) * val;
                }
            } else {
                if (!rows.count(id)) {
                    rows[id] = id;
                    sum += (n - cols.size()) * val;
                }
            }
        }
        return sum;
    }
};