class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](auto &a, auto &b){
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        int n = properties.size(), ans = 0, max_defense = 0;
        for (int i = 0; i < n; i++) {
            if (properties[i][1] < max_defense) {
                ans++;
            } else {
                max_defense = properties[i][1];
            }
        }
        return ans;
    }
};