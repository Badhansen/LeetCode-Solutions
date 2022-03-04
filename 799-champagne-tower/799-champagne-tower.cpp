class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> res(101, vector<double>(101, 0.0));
        res[0][0] = poured;
        for(int r = 0; r <= query_row; r++){
            for(int c = 0; c <= r; c++){
                double rem = (res[r][c] - 1.0) / 2.0;
                if(rem > 0.0){
                    res[r + 1][c] += rem;
                    res[r + 1][c + 1] = rem;
                }
            }
        }
        return min(1.0, res[query_row][query_glass]);
    }
};