class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<long long> csum(len + 1, 0);
        for(int i = 1; i <= len; i++){
            csum[i] = csum[i - 1] + nums[i - 1];
        }
        
        int answer = 1;
        
        for(int i = 0; i < len; i++){
            int start = 0, end = i;
            while(start < end){
                int mid = (start + end) / 2;
                long long sum = csum[i + 1] - csum[mid];
                long long asum = 1ll* (i - mid + 1) * nums[i];
                if(asum - sum <= k){
                    answer = max(answer, i - mid + 1);
                    end = mid;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        
        return answer;
    }
};