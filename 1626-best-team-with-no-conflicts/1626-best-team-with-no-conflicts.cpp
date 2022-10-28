class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int length = scores.size();
        vector<array<int, 2>> teams;
        for (int i = 0; i < length; i++) {
            teams.push_back({ages[i], scores[i]});
        }
        sort(teams.begin(), teams.end());
        vector<int> cache(length, 0);
        int answer = 0;
        for (int i = 0; i < length; i++) {
            cache[i] = teams[i][1];
            for (int j = 0; j < i; j++) {
                if (teams[j][1] <= teams[i][1]) {
                    cache[i] = max(cache[i], cache[j] + teams[i][1]);
                }
            }
            answer = max(answer, cache[i]);
        }
        return answer;
    }
};