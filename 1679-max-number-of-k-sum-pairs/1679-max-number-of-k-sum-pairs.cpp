class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size() - 1, answer = 0;
        while(low < high){
            int sum = nums[low] + nums[high];
            if(sum == k){
                answer++;
                low++, high--;
            }
            else if(sum > k){
                high--;
            }
            else{
                low++;
            }
        } 
        return answer;
    }
};