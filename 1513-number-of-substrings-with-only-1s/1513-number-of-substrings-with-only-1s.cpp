const int mod = 1e9 + 7;

class Solution {
public:
    int numSub(string s) {
        long long count = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                count++;
            }
            else{
                ans = ans % mod + (count * (count + 1) / 2) % mod;
                count = 0;
            }
        }
        ans = ans % mod + (count * (count + 1) / 2) % mod;
        return ans % mod;
    }
};