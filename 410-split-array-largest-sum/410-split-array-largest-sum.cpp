class Solution {
public:
    bool isValid(vector<int>& nums, int target, int m){
        int count = 1, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > target){
                sum = nums[i];
                count++;
            }
        }
        return count <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int start = 0, end = 0, answer = 0;
        for(int i = 0; i < nums.size(); i++){
            end += nums[i];
            start = max(start, nums[i]);
        }
        while(start <= end){
            int mid = (start + end) / 2;
            if(isValid(nums, mid, m)){
                answer = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return answer;
    }
};