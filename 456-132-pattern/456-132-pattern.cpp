class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> seq;
        int s3 = INT_MIN, len = nums.size();
        for(int i = len - 1; i >= 0; i--){
            if(nums[i] < s3){
                return true;
            }
            else{
                while(!seq.empty() && nums[i] > seq.top()){
                    s3 = seq.top();
                    seq.pop();
                }
            }
            seq.push(nums[i]);
        }
        return false;
    }
};