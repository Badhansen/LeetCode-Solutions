// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0], n = target.size();
        for(int i = 1; i < n; i++){
            if(target[i] > target[i - 1]) ans += target[i] - target[i - 1];
        }
        return ans;
    }
};

// Time: O(N), N = Length of array
// Space: O(1)