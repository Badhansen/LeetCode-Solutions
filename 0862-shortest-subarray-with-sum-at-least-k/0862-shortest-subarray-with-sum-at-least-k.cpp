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
            while (!queue.empty() && sum[right] - sum[queue.back()] <= 0) {
                queue.pop_back();
            }
            while (!queue.empty() && sum[right] - sum[queue.front()] >= k) {
                answer = min(answer, right - queue.front());
                queue.pop_front();
            }
            queue.push_back(right);
        }
        return answer >= n * 2 ? -1 : answer;
    }
};
