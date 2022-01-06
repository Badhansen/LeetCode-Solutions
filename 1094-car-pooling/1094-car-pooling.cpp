class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int len = trips.size();
        vector<int> line(1005, 0);
        for(auto &trip : trips){
            line[trip[1]] += trip[0];
            line[trip[2]] -= trip[0];
        }
        for(int i = 0; i < 1001; i++){
            if(line[i] > capacity)
                return false;
            line[i + 1] += line[i];
        }
        return true;
    }
};