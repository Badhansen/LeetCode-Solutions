// Programming Language Used: C++

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto el : accounts){
            int sum = 0;
            for(auto iel : el){
                sum += iel;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

// Time Complexity: O(N * M), here N = number of rows and M = number of columns present in the array
// Space Complexity: O(1), here we used only constant memory
