class Solution {
public:
    /*
    There are two kinds of the remainder.
        1. The remainder is 0 or 30. If the remainder is 0, it means the original time might be 60, 120, 180,
           and so on. We can take any combination of two remainders 0s as a pair. The number of such pair is                counts[0]*(counts[0]-1)/2. 
           If the remainder is 30, just like the remainder 0, any combination of two remainders 30 is a pair. The            number of such pair is alsocounts[0]*(counts[0]-1)/2.
        2. The remainder except 0 and 30. If remainder A is 15 and remainder B is 45, the number of such pair is            also counts[15]*counts[45].
    */
    int numPairsDivisibleBy60(vector<int>& time) {
        int counts[61] = {0};
        for(int i = 0; i < time.size(); i++){
            counts[time[i] % 60]++;
        }
        int ans = 0;
        int r = counts[0];
        ans += (r * (r - 1) / 2);
        r = counts[30];
        ans += (r * (r - 1) / 2);
        for(int i = 1; i < 30; i++){
            ans += counts[i] * counts[60 - i];
        }
        return ans;
    }
};