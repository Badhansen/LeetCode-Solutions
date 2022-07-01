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