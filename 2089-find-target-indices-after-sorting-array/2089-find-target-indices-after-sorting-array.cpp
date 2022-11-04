// @Author: KING-SEN
// 1 last try

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, equal = 0;
        
        for(auto &n : nums){ // O(N)
            if(n < target) count++;
            if(n == target) equal++;
        }
        
        if(equal == 0) return {};
        
        vector<int> ans;
        
        while(equal){ // O(Number of occurances)
            ans.push_back(count);
            count++;
            equal--;
        }
        
        return ans;
    }
};

// Time: O(N), N = Length of the array
// Space: O(1) ~ as the output array memory is discarted
