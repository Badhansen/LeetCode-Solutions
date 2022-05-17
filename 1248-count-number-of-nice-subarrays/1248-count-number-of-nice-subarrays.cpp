class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size(), ans = 0;
        vector<int> esumf(len, 0), esumb(len, 0);
        vector<int> odd;
        for(int i = 0; i < len; i++){
            nums[i] = !(nums[i] & 1);
            if(!nums[i]){
                odd.push_back(i);
            }
            if(i > 0){
                esumf[i] += esumf[i - 1] + nums[i];
            }
            else{
                esumf[i] = nums[i];
            }
            //cout << esumf[i] << " ";
        }
        //cout << endl;
        for(int i = len - 1; i >= 0; i--){
            if(i < len - 1){
                esumb[i] += esumb[i + 1] + nums[i];
            }
            else{
                esumb[i] = nums[i];
            }
            //cout << esumb[i] << " ";
        }
        //cout << endl;
        for(int i = k - 1; i < odd.size(); i++){
            int fr = esumf[odd[i - k + 1]], fprev = i - k + 1 > 0 ? esumf[odd[i - k]] : 0;
            int bk = esumb[odd[i]], bnext = i + 1 == odd.size() ? 0 : esumb[odd[i + 1]];        
            int ans1 = fr - fprev + 1;
            int ans2 = bk - bnext + 1;
            //cout << odd[i] << " " << bk << " " << bnext << " " <<  ans1 << " " << ans2 << endl;
            ans += ans1 * ans2;
        }
        return ans;
    }
};