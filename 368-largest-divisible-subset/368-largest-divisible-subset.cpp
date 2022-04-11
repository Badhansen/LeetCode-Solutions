class Solution {
public:
    int dp[1005][1005];
    int path[1005][1005];
    int solve(int pos, int last, vector<int>& nums){
        if(pos >= nums.size()){
            return 0;
        }
        int &ret = dp[pos][last];
        if(ret != -1){
            return ret;
        }
        int include = -1, notInclude = -1;
        if(last == 0){
            include = 1 + solve(pos + 1, pos, nums);
        }
        else{
            if(nums[pos] % nums[last] == 0){
                include = 1 + solve(pos + 1, pos, nums);
            }
        }
        notInclude = solve(pos + 1, last, nums);
        ret = max(include, notInclude);
        if(ret == include){
            path[pos][last] = 1; // 1 means include
        }
        else{
            path[pos][last] = 2;
        }
        return ret;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof dp);
        memset(path, -1, sizeof path);
        solve(1, 0, nums);
        int pos = 1, last = 0;
        vector<int> answer;
        while(pos != nums.size()){
            if(path[pos][last] == 1){
                answer.push_back(nums[pos]);
                last = pos;
            }
            pos++;
        }
        return answer;  
    }
};