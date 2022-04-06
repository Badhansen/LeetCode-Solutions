class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[3005][5][305];
    int solve(int pos, int count, int sum, vector<int>& arr){
        if(pos >= arr.size()){
            if(sum == 0 && count == 3){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(count > 3 || sum < 0){
            return 0;
        }
        if(count == 3 && sum == 0){
            return 1;
        }
        int &ret = dp[pos][count][sum];
        if(ret != -1){
            return ret;
        }
        ret = 0;
        ret = (solve(pos + 1, count + 1, sum - arr[pos], arr) % mod + 
            solve(pos + 1, count, sum, arr) % mod) % mod;
        return ret;
        
    }
    int threeSumMulti(vector<int>& arr, int target) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, target, arr);
    }
};