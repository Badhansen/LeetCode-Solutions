class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        map<char, bool> maps;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (maps.count(s[i])) {
                ans++;
                maps.clear();
            }
            maps[s[i]] = true;
        }
        return ans;
    }
};