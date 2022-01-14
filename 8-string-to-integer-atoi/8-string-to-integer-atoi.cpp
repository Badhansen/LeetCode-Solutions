class Solution {
public:
    
    int myAtoi(string str) {
        string st = "";
        int pos = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] != ' '){
                pos = i;
                break;
            }
        }
        st = str.substr(pos, str.size() - pos);
        long long res = 0;
        bool neg = false;
        pos = 0;
        if(st[0] == '-'){
            pos = 1;
            neg = true;
        }
        if(st[0] == '+'){
            pos = 1;
        }
        for(int i = pos; i < st.size(); i++){
            if(st[i] >= '0' && st[i] <= '9')
                res = res * 10 + int(st[i] - '0');
            else{
                if(neg) return -1 * res;
                return res;
            }
            if(neg && -1 * res <= INT_MIN) return INT_MIN;
            if(res >= INT_MAX && neg == false) return INT_MAX;
        }
        if(neg) return -1 * res;
        return res;
    }
};