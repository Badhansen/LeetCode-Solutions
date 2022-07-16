class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (auto &t : timePoints) {
            int time = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
            minutes.push_back(time);
        }
        sort(minutes.begin(), minutes.end());
        minutes.push_back(minutes[0] + 60 * 24);
        int answer = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            answer = min(answer, minutes[i] - minutes[i - 1]); 
        }
        return answer;
    }
};

// Time: O(N)
// Space: O(N)