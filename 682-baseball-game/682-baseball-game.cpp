class Solution {
private:
    int cnt = 0;
    vector<int> Round;
public:
    int calPoints(vector<string>& ops) {
        int len = ops.size(), ans = 0;
        Round.resize(len);
        cnt = 0;
        for(int i = 0; i < len; i++){
            int score = 0;
            char c = ops[i][0];
            if(c == 'D'){
                if(cnt > 0) ans += 2 * Round[cnt - 1];
                Round[cnt++] = 2 * Round[cnt - 1];
            }
            else if(c == 'C'){
                if(cnt > 0){
                    ans -= Round[cnt - 1];
                    cnt--;
                }
                //Round[cnt++] = ans;
            }
            else if(c == '+'){
                if(cnt > 1){
                    ans += Round[cnt - 1] + Round[cnt - 2];
                    //printf("%d %d\n", Round[cnt - 1], Round[cnt - 2]);
                    Round[cnt++] = Round[cnt - 1] + Round[cnt - 2];
                }
                else if(cnt > 0){
                    ans += Round[cnt - 1];
                    Round[cnt++] = Round[cnt - 1];
                }

            }
            else if(c == '-'){
                for(int j = 1; ops[i][j] != '\0'; j++){
                    int d = ops[i][j] - '0';
                    score = score * 10 + d;
                }
                score *= -1;
                ans += score;
                Round[cnt++] = score;
            }
            else{
                for(int j = 0; ops[i][j] != '\0'; j++){
                    int d = ops[i][j] - '0';
                    score = score * 10 + d;
                }
                Round[cnt++] = score;
                ans += score;
            }
        }
        return ans;
    }
};