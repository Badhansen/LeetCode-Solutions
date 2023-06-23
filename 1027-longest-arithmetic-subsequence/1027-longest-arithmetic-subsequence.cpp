// not my code
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size();
        int res=1;
        vector<vector<int>> dp(n + 1, vector<int>(1001, 1));
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int diff=nums[i]-nums[j];
                dp[i][diff+500]= max(dp[i][diff+500],1+dp[j][diff+500]);
                res= max(res,dp[i][diff+500]);
                
            }
        }
        return res;
        
        
    }
};