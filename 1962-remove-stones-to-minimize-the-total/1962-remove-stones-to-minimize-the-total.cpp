class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> que;
        for (auto p : piles) {
            que.push(p);
        }
        while (!que.empty() && k && que.top() != 1) {
            int val = que.top();
            que.pop();
            que.push(val / 2 + (val & 1));
            k--;
        }
        int sum = 0;
        while (!que.empty()) {
            int val = que.top();
            que.pop();
            sum += val;
        }
        return sum;
    }
};