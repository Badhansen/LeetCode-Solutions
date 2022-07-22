class Solution {
public:
    int AtMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int start = 0, end = 0, answer = 0, count = 0;
        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;
            while (freq.size() > k) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) {
                    freq.erase(nums[start]);
                }
                start++;
            }
            answer += end - start;
        }
        return answer;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return AtMostKDistinct(nums, k) - AtMostKDistinct(nums, k - 1);
    }
};