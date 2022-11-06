// @Author: KING-SEN

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& a) {
        auto cmp = [&](int i, int j) {
            if (a[i] != a[j]) return a[i] > a[j];
            return i < j;
        };
        int n = a.size();
        vector <int> id(n);
        for (int i = 0; i < n; i++) id[i] = i;
        sort(id.begin(), id.end(), cmp);
        // for (int i = 0; i < n; i++) {
        //     cout << id[i] << " " << a[id[i]] << endl;
        // }
        vector <int> ans(n, -1);
        set <int> all;
        for (int i = 0; i < n; i++) {
            int j = id[i];
            auto it = all.lower_bound(j);
            if (it != all.end()) {
                // cout << "low " << j << " " << *it << endl;
                ++it;
                if (it != all.end()) ans[j] = a[*it];
            } else {
                // cout << "low " << j << " " << "end" << endl;
            }
            all.insert(j);
        }
        return ans;
    }
};