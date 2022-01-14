#define MAX 200005

class Solution {
private:
    vector<int> count, dp;
public:
    int solve(int pos){
        if(pos >= MAX - 4)
            return 0;
        
        int &ret = dp[pos];
    
        if(ret != -1) return ret;
    
        int include = pos * count[pos] + solve(pos + 2);
        int exclude = solve(pos + 1);
        
        return ret = max(include, exclude);
    }
    int deleteAndEarn(vector<int>& nums) {
        count.resize(MAX, 0);
        dp.resize(MAX, -1);        
        for(auto &n : nums){
            count[n]++;
        }
        
        return solve(0);
    }
};