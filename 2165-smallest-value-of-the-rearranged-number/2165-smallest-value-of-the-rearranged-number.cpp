class Solution {
public:
    long long smallestNumber(long long num) {
        string val = to_string(abs(num));
        sort(val.begin(), val.end());
        if(num < 0){
            reverse(val.begin(), val.end());
            return -1ll * stoll(val); 
        }
        if(num == 0) return num;
        int idx = val.find_first_not_of('0');
        swap(val[0], val[idx]);
        return stoll(val);
    }
};