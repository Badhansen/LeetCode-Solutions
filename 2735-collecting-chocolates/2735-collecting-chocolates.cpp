class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> costs(n, INT_MAX);
        long long answer = LONG_MAX;
        for (int rotate = 0; rotate < n; rotate++) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                costs[i] = min(costs[i], 1ll * nums[(i + rotate) % n]);
                sum += costs[i];
            }
            answer = min(answer, sum + 1ll * rotate * x);
        }
        return answer;
    }
};
