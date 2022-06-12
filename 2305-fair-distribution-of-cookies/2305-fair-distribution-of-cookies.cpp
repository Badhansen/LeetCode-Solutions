/*
class Solution {
public:
    bool solve(vector<int>& nums, int mid, int k){
        int count = 0, sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > mid) return false;
            sum += nums[i];
            if(sum > mid){
                count++;
                sum = nums[i];
            }
        }
        count++;
        if(count <= k) return true;
        return false;
    }
    int bSearch(vector<int>& cookies, int low, int high, int k){
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(cookies, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(), cookies.end());
        int low = *max_element(cookies.begin(), cookies.end());
        int high = accumulate(cookies.begin(), cookies.end(), 0);
        int ans = INT_MAX;
        do{
            ans = min(ans, bSearch(cookies, low, high, k));
        }while(next_permutation(cookies.begin(), cookies.end()));
        return ans;
    }
};
*/
class Solution {
public:
    int ans;
    void backtrack(int pos, vector<int>& cookies, vector<int>& buckets, int maxx){
        if(pos == cookies.size()){
            ans = min(ans, maxx);
            return;
        }
        for(int b = 0; b < buckets.size(); b++){
            buckets[b] += cookies[pos];
            backtrack(pos + 1, cookies, buckets, max(maxx, buckets[b]));
            buckets[b] -= cookies[pos];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        ans = INT_MAX;
        vector<int> buckets(k, 0);
        backtrack(0, cookies, buckets, 0);
        return ans;
    }
    
};