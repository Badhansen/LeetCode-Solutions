class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> winner, loser;
        for (auto m : matches) {
            winner[m[0]]++;
            loser[m[1]]++;
        }
        vector<int> win, lose;
        for (auto [key, val] : winner) {
            if (!loser.count(key)) {
                win.push_back(key);
            }
        }
        for (auto [key, val] : loser) {
            if (val == 1) {
                lose.push_back(key);
            }
        }
        return {win, lose};
    }
};