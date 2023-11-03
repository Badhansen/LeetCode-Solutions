class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string push = "Push", pop = "Pop";
        vector<string> res;
        int p = 1;
        for (auto t : target) {
            while (p <= t) {
                if (p == t) {
                    res.push_back(push);
                } else {
                    res.push_back(push);
                    res.push_back(pop);
                }
                p++;
            }
        }
        return res;
    }
};