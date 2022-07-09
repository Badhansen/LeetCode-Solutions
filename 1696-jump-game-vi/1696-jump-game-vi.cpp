class Solution {
private:
    priority_queue<pair<int, int>> que;
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int maxval = nums[0];
        que.push({nums[0], 0});
        for(int index = 1; index < n; index++){
            while(!que.empty() && index - que.top().second > k){
                que.pop();
            }
            pair<int, int> topval = que.top();
            maxval = nums[index] + topval.first;
            que.push({maxval, index});
        }
        return maxval;
    }
};
// Time: O(N log K)
// Space: O(K)