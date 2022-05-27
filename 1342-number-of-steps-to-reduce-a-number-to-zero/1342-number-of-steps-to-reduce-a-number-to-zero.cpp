class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while(num){
            if(num & 1) num = num ^ 1;
            else num = num >> 1;
            cnt++;
        }
        return cnt;
    }
};