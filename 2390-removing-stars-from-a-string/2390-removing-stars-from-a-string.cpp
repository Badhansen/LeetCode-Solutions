class Solution {
public:
    string removeStars(string s) {
        string store;
        for (auto c : s) {
            if (c != '*') {
                store.push_back(c);
            } else {
                if (!store.empty()) {
                    store.pop_back();
                }
            }
        }
        return store;
    }
};