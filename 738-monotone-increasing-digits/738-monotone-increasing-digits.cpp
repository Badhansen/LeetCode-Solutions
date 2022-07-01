class Solution {
public:
    vector<int> intToVec(int n){
        if(n == 0) return {0};
        vector<int> res;
        while(n){
            int rem = n % 10;
            res.push_back(rem);
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int monotoneIncreasingDigits(int n) {
        vector<int> digit = intToVec(n);
        int len = digit.size();
        int isEnd = len - 1, result = 0;
        for(int i = len - 1; i > 0; i--){
            if(digit[i - 1] > digit[i]){
                isEnd = i - 1;
                digit[i - 1]--;
            }
        }
        for(int i = isEnd + 1; i < len; i++){
            digit[i] = 9;
        }
        for(int i = 0; i < len; i++){
            result = result * 10 + digit[i];   
        }
        return result;
    }
};

/*
// bfs approach

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        queue<long long> que;
        for(int i = 0; i <= 9; i++){
            que.push(i);
        }
        int result = INT_MIN;
        while(!que.empty()){
            int val = que.front();
            que.pop();
            if(val > n){
                break;
            }
            result = max(result, val);
            int rem = val % 10;
            for(int i = rem; i <= 9; i++){
                que.push(1ll * val * 10 + i);
            }
        }
        return result;
    }
};
*/