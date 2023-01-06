class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0, count = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (sum + costs[i] <= coins) {
                count++;
                sum += costs[i];
            }
        }
        return count;
    }
};