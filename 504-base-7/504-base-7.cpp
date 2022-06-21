class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return to_string(num);
        bool neg = num < 0 ? true : false;
        num = num < 0 ? -num : num;
        string res = "";
        while(num){
            int rem = num % 7;
            res += to_string(rem);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        if(neg) return "-" + res;
        return res;
    }
};