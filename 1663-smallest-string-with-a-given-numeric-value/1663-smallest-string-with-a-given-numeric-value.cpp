class Solution {
public:
    string getSmallestString(int n, int k) {
        string answer(n, 'a');
        k -= n;
        for(int i = n - 1; i >= 0; i--){
            if(k == 0){
                break;
            }
            answer[i] += min(k, 25);
            k -= min(k, 25);
        }
        return answer;
    }
};