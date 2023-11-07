class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> monsters;
        for (int i = 0; i < n; i++) {
            int s = dist[i] / speed[i] + (dist[i] % speed[i] == 0 ? 0 : 1);
            monsters.push_back(s);
        }
        sort(monsters.begin(), monsters.end());
        int seconds = 1;
        int kills = 1;
        for (int i = 1; i < n; i++) {
            if (monsters[i] <= seconds) {
                return kills;
            } else {
                kills++;
            }
            seconds++;
        }
        return kills;
    }
};