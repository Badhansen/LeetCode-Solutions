// @Author: KING-SEN

const int kMax = 101;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(kMax, 0);
        int length = nums.size();
        for(int i = 0; i < length; i++){
            count[nums[i]]++;
        }
        for(int i = 1; i < kMax; i++){
            count[i] += count[i - 1];
        }
        vector<int> answer(length, 0);
        for(int i = 0; i < length; i++){
            answer[i] = nums[i] > 0 ? count[nums[i] - 1] : 0;
        }
        return answer;
    }
};
/*
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
*/