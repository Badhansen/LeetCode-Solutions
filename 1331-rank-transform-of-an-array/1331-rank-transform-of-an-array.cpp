// @Author: KING-SEN
// 1 last try

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 0) return {};
        
        map<int, int> seen; 
        vector<int> ans(n);
        
        for(auto n : arr){ // O(N)
            seen[n] = true; // O(log N)
        }
        
        int rank = 1;
        
        for(auto &mp : seen){ // O(N)
            mp.second = rank;
            rank++;
        }
        for(int i = 0; i < n; i++){ // O(N)
            ans[i] = seen[arr[i]];
        }
        
        return ans;
    }
};

// Time: O(N log N), N = length of the array
// Space: O(N)