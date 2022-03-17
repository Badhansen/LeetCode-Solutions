class Solution {
public:
    int scoreOfParentheses(string S) {
        int size = S.size(), answer = 0, pw = 0;
        for(int i = 1; i < size; i++){
            if(S[i] == '(') pw++;
            else if(S[i - 1] == '(') answer += (1 << pw), pw--;
            else pw--;
        }
        return answer;
    }
};