class Solution {
public:
    bool check(vector<int>& weights, int mid, int d){
        int sum = 0;
        int days = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                days++;
                sum = weights[i];
            }
        }
        if (days >= d) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0;
        int low = 0, high;
        int ans = 0;
        for (int i = 0; i < weights.size(); i++) {
            total += weights[i];
            low = max(low, weights[i]);
        }
        high = total;
        while (low < high) {
            int mid = (low + high) / 2;
            if (check(weights, mid, days)) {
                low = mid + 1;
            } else{
                high = mid;
            }
        }
        return low;
    }
};