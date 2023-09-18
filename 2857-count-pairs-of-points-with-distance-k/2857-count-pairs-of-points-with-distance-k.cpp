class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        unordered_map<int, unordered_map<int, int>> counts;
        int res = 0, x1, y1, x2, y2;
        /*
            (x1 ^ x2) + (y1 ^ y2) = k

            Let (x1 ^ x2) = value
            Then the equation become like this:-

            => value + (y1 ^ y2) = k
            => (y1 ^ y2) = k - value
            

            So, we got 2 equations.
            (x1 ^ x2) = value 
            => x2 = (value ^ x1)   ------------(1)
            
            (y1 ^ y2) = k - value 
            => y2 = (k - value) ^ y1 ----------(2)

        */
        for (int i = 0; i < n; i++) {
            x1 = coordinates[i][0], y1 = coordinates[i][1];
            
            for (int value = 0; value <= k; value++) {
                x2 = value ^ x1, y2 = (k - value) ^ y1;
                res += counts[x2][y2];
            }
            counts[x1][y1]++;
        }
        return res;
    }
};