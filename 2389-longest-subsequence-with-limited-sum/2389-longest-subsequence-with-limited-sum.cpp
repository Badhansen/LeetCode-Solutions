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