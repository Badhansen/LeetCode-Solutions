/*
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int nums_len = nums.size(), queries_len = queries.size();
        vector<int> answer(queries_len, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries_len; i++) {
            int max_len = 0, sum = 0;
            for (int right = 0; right < nums_len; right++) {
                sum += nums[right];
                if (sum > queries[i]) {
                    break;
                } else {
                    max_len = max(max_len, right + 1);   
                }
            }
            answer[i] = max_len;
        }
        return answer;
    }
};
// Time: O(N log N + N * M)
*/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int nums_len = nums.size(), queries_len = queries.size();
        vector<int> answer;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums_len; i++) {
            nums[i] += nums[i - 1];
        }
        for (auto q : queries) {
            int index = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            answer.push_back(index);
        }
        return answer;
    }
};
