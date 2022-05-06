class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long fmax = 1LL * INT_MIN - 1, smax = 1ll * INT_MIN - 1, tmax = 1ll * INT_MIN - 1;
        for(long long n : nums){
            if(n > fmax){
                tmax = smax;
                smax = fmax;
                fmax = n;
            }
            else if(n > smax && fmax > n){
                tmax = smax;
                smax = n;
            }
            else if(n > tmax && smax > n){
                tmax = n;
            }
        }
        if(tmax == 1ll * INT_MIN - 1){
            return fmax;
        }
        return tmax;
    }
};