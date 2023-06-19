class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int answer = 0, prev = 0;
        for (int i = 0; i < gain.size(); i++) {
            answer = max(answer, prev + gain[i]);
            prev += gain[i];
        }
        return answer;
    }
};