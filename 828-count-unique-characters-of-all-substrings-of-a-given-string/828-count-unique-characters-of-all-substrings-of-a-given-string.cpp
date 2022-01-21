class Solution {
public:
    int uniqueLetterString(string s) {
        int answer = 0, count = 0;
        vector<int> prevCnt(26, 0);
        vector<int> lastIdx(26, -1);
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'A';
            int currentCnt = i - lastIdx[idx];
            count = count - prevCnt[idx] + currentCnt;
            answer += count;
            prevCnt[idx] = currentCnt;
            lastIdx[idx] = i;
        }
        return answer;
    }
};