class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> left(n), right(n);
        left[0] = nums[0], right[0] = nums[n - 1];
        for(int i = 1, j = n - 2; i < n; i++, j--){
            left[i] = left[i - 1] + nums[i];
            right[i] = right[i - 1] + nums[j];
        }
        
        int pos = lower_bound(left.begin(), left.end(), x) - left.begin();
        int ans = INT_MAX;
        
        if(pos == 0){
            if(x == left[0]) ans = 1;
            else ans = INT_MAX;
        }
        else{
            if(pos < n && left[pos] == x) ans = pos + 1;
            else ans = INT_MAX;
        }
        //cout << ans << endl;
        
        pos = lower_bound(right.begin(), right.end(), x) - right.begin();
        
        if(pos == 0){
            if(x == right[0]) ans = 1;
        }
        else{
            if(pos < n && right[pos] == x) ans = min(ans, pos + 1);
        }
        //cout << ans << endl;
        for(int i = 1; i <= n; i++){
            int rem = x - left[i - 1];
            if(rem <= 0) break;
            pos = lower_bound(right.begin(), right.end(), rem) - right.begin();
            if(pos == n) continue;
            if(left[i - 1] + right[pos] == x) ans = min(ans, i + pos + 1);
        }
        
        for(int i = 1; i <= n; i++){
            int rem = x - right[i - 1];
            if(rem <= 0) break;
            pos = lower_bound(left.begin(), left.end(), rem) - left.begin();
            if(pos == n) continue;
            if(right[i - 1] + left[pos] == x) ans = min(ans, i + pos + 1);
        }
        
        return ans > n ? -1 : ans;
    }
};
