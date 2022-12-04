class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int len = nums.size();
        vector<long long> sums(len, 0);
        sums[0] = nums[0];
        for(int i = 1; i < len; i++){
            sums[i] = sums[i - 1] + nums[i];
        }
        int index = 0;
        long long diff = INT_MAX;
        for(int i = 0; i < len; i++){
            long long curr = sums[i];
            long long back = sums[len - 1] - sums[i];
            long long div1 = curr / (i + 1);
            long long div2 = 0;
            if(len - i - 1 > 0){
                div2 = back / (len - i - 1);
            }
            if(diff > abs(div1 - div2)){
                diff = abs(div1 - div2);
                index = i;
            }
        }
        return index;
    }
};