const int kMax = 2005;

class Solution {
private:
    unordered_map<int, int> dp[kMax];
public:
    int solve(int pos, int prev, vector<int>& a, vector<int>& b) {
        if (pos >= a.size()) {
            return 0;
        }
        if (dp[pos].find(prev) != dp[pos].end()) {
            return dp[pos][prev];
        }
        int cost = 1e9;
        if (a[pos] > prev) {
            cost = solve(pos + 1, a[pos], a, b);
        } 
        int index = upper_bound(b.begin(), b.end(), prev) - b.begin();
        if (index < b.size()) {
            cost = min(cost, 1 + solve(pos + 1, b[index], a, b));
        }
        return dp[pos][prev] = cost;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int ans = solve(0, -1, arr1, arr2);
        return ans < 1e9 ? ans : -1;
    }
};