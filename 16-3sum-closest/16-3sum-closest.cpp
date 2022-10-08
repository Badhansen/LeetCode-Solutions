class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for(int i = 0; i < n && diff != 0; i++){
            int low = i + 1, high = n - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(abs(target - sum) < abs(diff)){
                    diff = target - sum;
                }
                if(sum < target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return target - diff;
    }
};