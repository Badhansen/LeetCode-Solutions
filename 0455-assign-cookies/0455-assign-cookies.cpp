class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0, index = 0;
        while(index < s.size() && res < g.size()) {
            if (s[index] >= g[res]) {
                index++, res++;
            } else {
                index++;
            }
        }
        return res;
    }
};