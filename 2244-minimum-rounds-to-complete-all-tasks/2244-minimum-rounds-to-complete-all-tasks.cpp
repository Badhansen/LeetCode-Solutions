class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rounds = 0;
        map<int, int> count;
        for(auto &item : tasks){
            count[item]++;
        }
        for(auto [key, value] : count){
            if(value & 1){
                if(value % 3 == 0){
                    rounds += value / 3;
                    continue;
                }
                while(value > 4){
                    value -= 3;
                    rounds++;
                }
                if(value % 2 != 0){
                    return -1;
                }
                rounds += value / 2;
            }
            else if(value % 2 == 0){
                if(value % 3 == 0){
                    rounds += value / 3;
                    continue;
                }
                while(value > 4){
                    value -= 3;
                    rounds++;
                }
                if(value % 2 != 0){
                    return -1;
                }
                rounds += value / 2;
            }
            else if(value % 2 == 0){
                rounds += value / 2;
            }
            else{
                return -1;
            }
        }
        return rounds;
    }
};