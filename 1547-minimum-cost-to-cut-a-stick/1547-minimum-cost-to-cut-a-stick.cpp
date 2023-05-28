class Solution {
private:
    map<pair<int, int>, int> dp;
public:
    int MinCut(int left, int right, const vector<int>& cuts) {
        if (left == right) {
            return 0;
        }
        if (dp.find({left, right}) != dp.end()) {
            return dp[{left, right}];
        }
        int result = INT_MAX;
        for (auto &cut : cuts) {
            if (cut > left && cut < right) {
                result = min(result, right - left + MinCut(left, cut, cuts) + MinCut(cut, right, cuts));
            }
        }
        return dp[{left, right}] = result == INT_MAX ? 0 : result;
    }
    int minCost(int n, vector<int>& cuts) {
        return MinCut(0, n, cuts);
    }
};