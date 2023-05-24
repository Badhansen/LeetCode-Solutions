class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        deque<int> queue;
        int answer = n * 2;
        for (int right = 0; right <= n; right++) {
			// if sum at last in dq >= current sum, we remove the last values from dq
            while (!queue.empty() && sum[queue.back()] >= sum[right]) {
                queue.pop_back();
            }
	        // if sum at index right - sum at index at start of dq >= k we remove the start index of dq
            while (!queue.empty() && sum[right] - sum[queue.front()] >= k) {
                answer = min(answer, right - queue.front());
                queue.pop_front();
            }
            queue.push_back(right);
        }
        return answer >= n * 2 ? -1 : answer;
    }
};

// Time Complexity: O(N), where N is the length of nums.
// Space Complexity: O(N).