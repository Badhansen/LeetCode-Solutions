// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int maxPower(string s) {
        int count = 1, answer = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i - 1] == s[i]) count++;
            else{
                count = 1;
            }
            answer = max(answer, count);
        }
        return answer;
    }
};

// Time: O(N), N = numbers of elements
// Space: O(1)