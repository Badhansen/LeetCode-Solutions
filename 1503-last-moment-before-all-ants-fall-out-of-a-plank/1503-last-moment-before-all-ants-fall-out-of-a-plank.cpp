class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (auto l : left) {
            res = max(res, l);
        }
        for (auto r : right) {
            res = max(res, n - r);
        }
        return res;
    }
};