class Solution {
public:
    int brokenCalc(int X, int Y) {
        int answer = 0;
        while(Y > X){
            answer++;
            if(Y & 1) Y++;
            else Y /= 2;
        }
        return answer + (X - Y);
    }
};