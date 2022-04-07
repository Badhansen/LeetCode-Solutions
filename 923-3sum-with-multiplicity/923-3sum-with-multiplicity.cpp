class Solution {
public:
    const int mod = 1e9 + 7;
    int threeSumMulti(vector<int>& arr, int target) {
        int len = arr.size(), ans = 0;
        unordered_map<int, int> count;

        for(int i = 0; i < len; i++) {
            ans = (ans + count[target - arr[i]]) % mod;
            for(int j = 0; j < i; j++){
                count[arr[i] + arr[j]]++;
            }
        }
        return ans;
    }
};