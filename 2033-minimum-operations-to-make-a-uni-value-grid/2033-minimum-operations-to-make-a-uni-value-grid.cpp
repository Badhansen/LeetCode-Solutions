class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        for(auto &row : grid){
            values.insert(values.end(), row.begin(), row.end());
        }
        sort(values.begin(), values.end());
        int n = values.size();
        int mid = n / 2;
        int median = values[mid];
        int result = 0;
        for(int i = 0; i < n; i++){
            int diff = abs(median - values[i]);
            if(diff % x != 0) return -1;
            result += diff / x;
        }
        return result;
    }
};