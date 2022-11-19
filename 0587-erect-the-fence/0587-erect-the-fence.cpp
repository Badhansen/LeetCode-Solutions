// N^2 Got TLE and I don't know the Andrew's method
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        // Andrew's monotone chain method.
        sort(begin(points), end(points), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        // left to right
        const int n = size(points);
        vector<vector<int>> ans;
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        // If all points are along a line, size(ans) is n after left to right procedure.
        if (size(ans) == n) return ans;

        // right to left
        for (int i = n - 2; i >= 0; --i) {
            while (size(ans) > 1 && orientation(ans[size(ans) - 2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        ans.pop_back();
        return ans;
    }

    static int orientation(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
};