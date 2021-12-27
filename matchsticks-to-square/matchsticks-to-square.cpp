typedef long long Long;
class Solution {
public:
    bool rec(int pos, vector<int>& matchsticks, Long sides[4]){
        if(pos == matchsticks.size()){
            if(sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0) return true;
            return false;
        }
        for(int i = 0; i < 4; i++){
            if(matchsticks[pos] > sides[i]) continue;
            sides[i] -= matchsticks[pos];
            if(rec(pos + 1, matchsticks, sides)) return true;
            sides[i] += matchsticks[pos];
        }
        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        Long sum = 0;
        for(auto &el : matchsticks){
            sum += el;
        }
        if(sum % 4) return false;
        int length = sum / 4;
        Long sides[4] = {length, length, length, length};
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return rec(0, matchsticks, sides);
    }
};