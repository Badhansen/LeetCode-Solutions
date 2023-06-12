class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return {};
        }
        int curr = nums[0], prev = nums[0];
        vector<string> answer;
        string result = to_string(prev);
        for(int i = 1; i < len; i++){
            if(nums[i - 1] + 1 != nums[i]){
                if(prev == nums[i - 1]){
                    answer.push_back(result);
                }
                else{
                    result.append("->" + to_string(nums[i - 1]));
                    answer.push_back(result);
                }
                prev = nums[i];
                result = to_string(prev);
            }
        }
        if(prev == nums[len - 1]){
            answer.push_back(result);
        }
        else{
            result.append("->" + to_string(nums[len - 1]));
            answer.push_back(result);
        }
        return answer;
    }
};