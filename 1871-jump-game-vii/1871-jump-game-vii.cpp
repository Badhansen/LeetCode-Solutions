//@Author: KING-SEN
// 1 last try

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        for(int i = 0, j = 0; i < s.size(); i++){
            if(i == 0 || s[i] == '2'){
                for(j = max(j, i + minJump); j <= min(i + maxJump, (int)s.size() - 1); j++){
                    if(s[j] == '0') s[j] = '2';
                }
            }
        }
        return s[s.size() - 1] == '2';
    }
};

// Time: O(N), N = length of the array
// Space: O(1)