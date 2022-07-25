/*
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> que;
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            nums[i] += !que.empty() ? que.front() : 0;
            res = max(res, nums[i]);
            while (!que.empty() && nums[i] > que.back()) {
                que.pop_back();
            }
            if (nums[i] > 0) {
                que.push_back(nums[i]);    
            }
            if (i >= k && !que.empty() && que.front() == nums[i - k]) {
                que.pop_front();
            }
        }
        return res;
    }
};
*/
/*
    Because all element are pushed and popped at most once.
    Time O(N)

    Because at most O(K) elements in the deque.
    Space O(K)
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<array<int, 2>> que;
        int ret = nums[0], curr;
        que.push({nums[0], 0});
        for (int i = 1; i < nums.size(); i++) {
            while (!que.empty() && que.top()[1] < i - k) {
                que.pop();
            }
            curr = max(0, que.top()[0]) + nums[i];
		    ret = max(ret, curr);
            que.push({curr, i});
        }
        return ret;
    }
};
/*
    Time: O(Nlog(k))
    Space O(k)
*/
