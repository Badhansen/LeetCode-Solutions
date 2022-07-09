class Solution {
private:
    deque<int> que;
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        que.push_back(0);
        for(int index = 1; index < n; index++){
            nums[index] = nums[index] + nums[que.front()];
            while(!que.empty() && nums[index] >= nums[que.back()]){
                que.pop_back();
            }
            que.push_back(index);
            while(index - que.front() >= k){
                que.pop_front();
            }
        }
        return nums[n - 1];
    }
};

// Time: O(N)
// Space: O(K)

/*
class Solution {
private:
    priority_queue<pair<int, int>> que;
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int maxval = nums[0];
        pair<int, int> topval;
        que.push({nums[0], 0});
        for(int index = 1; index < n; index++){
            while(!que.empty() && index - que.top().second > k){
                que.pop();
            }
            topval = que.top();
            maxval = nums[index] + topval.first;
            que.push({maxval, index});
        }
        return maxval;
    }
};
// Time: O(N log K)
// Space: O(K)
*/