/*
Here, we change every number to be a median. Note that we can find a median in O(n) using a quickselect algo (nth_element).
*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
        for(auto &row : grid){
            values.insert(values.end(), row.begin(), row.end());
        }
        int n = values.size();
        int mid = n / 2;
        nth_element(values.begin(), values.begin() + mid, values.end());
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

// Time: O(N), N = all the elements of grid
// Space: O(N)