class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<array<int, 2>> points;
        for (auto b : buildings) {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        sort(points.begin(), points.end());
        int prev = 0, curr = 0;
        multiset<int> seen;
        vector<vector<int>> res;
        seen.insert(0);
        for (auto p : points) {
            // If i.second is less than zero, then it means it is left boundary.
            if (p[1] < 0) {
                seen.insert(-p[1]);
            } else { // else it is right boundary.
                seen.erase(seen.find(p[1]));
            }
            curr = *seen.rbegin();
            if (curr != prev) {
                res.push_back({p[0], curr});
                prev = curr;
            }
        }
        return res;
    }
};