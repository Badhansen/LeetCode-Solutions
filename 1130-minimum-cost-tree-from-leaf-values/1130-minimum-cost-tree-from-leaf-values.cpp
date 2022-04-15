class Solution {
private:
    int cache[45][45];
public:
    int largestLeaf(int start, int end, const vector<int>& nums){
        if(start > end){
            return 1;
        }
        if(start == end){
            return nums[start];
        }
        int maxValue = 0;
        for(int i = start; i <= end; i++){
            maxValue = max(maxValue, nums[i]);
        }
        return maxValue;
    }
    int solve(int start, int end, const vector<int>& nums){
        if(start == end){
            return 0;
        }
        int &result = cache[start][end];
        if(result != -1){
            return result;
        }
        result = INT_MAX / 2;
        for(int i = start; i <= end; i++){
            int leftSum = solve(start, i, nums);
            int rightSum = solve(i + 1, end, nums);
            result = min(result, leftSum + rightSum + largestLeaf(start, i, nums) * largestLeaf(i + 1, end, nums));
        }
        return result;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(cache, -1, sizeof cache);
        return solve(0, arr.size() - 1, arr);
    }
};