class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        int prev = nums[0];
        for(int i = 0; i < len;){
            int j = i + 1;
            while(j < len && nums[j] == prev){
                j++;
                ans++;
            }
            i = j + 1;
            if(i < len){
                prev = nums[i];
            }
            else{
                break;
            }
        }
        return (len - ans) & 1 ? ans + 1 : ans;
    }
};