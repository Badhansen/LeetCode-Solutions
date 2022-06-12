class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;
        int left = 0, score = INT_MIN, currsum = 0;
        for(int right = 0; right < n; ){
            if(count[nums[right]] > 0){
                currsum -= nums[left];
                count[nums[left]]--;
                left++;
            }
            else{
                currsum += nums[right];
                score = max(score, currsum);
                count[nums[right]]++;
                right++;
            }
        }
        return score;
    }
};