class Solution {
public:
    int MaxConsecutiveXs(string s, char x) {
        int count = 0, answer = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == x) count++;
            else{
                count = 0;
            }
            answer = max(answer, count);
        }
        return answer;
    }
    bool checkZeroOnes(string s) {
        return MaxConsecutiveXs(s, '1') > MaxConsecutiveXs(s, '0');
    }
};