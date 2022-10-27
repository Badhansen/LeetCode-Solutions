// @Author: KING-SEN

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> elements = nums;
        sort(elements.begin(), elements.end());
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            int total = lower_bound(elements.begin(), elements.end(), nums[i]) - elements.begin();
            answer.push_back(total);
        }
        return answer;
    }
};