class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(), candies.end());
        vector<bool> answer;
        for (auto &c : candies) {
            answer.push_back(c + extraCandies >= maxCandy);
        }
        return answer;
    }
};