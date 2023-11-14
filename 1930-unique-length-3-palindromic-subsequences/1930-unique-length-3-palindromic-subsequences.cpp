class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> pos[26];
        for(int i = 0; i < s.size(); i++){
            pos[s[i] - 'a'].push_back(i);
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(!pos[i].size()) continue;
            int p = pos[i][0], q = INT_MAX, r;
            for(int j = 0; j < 26; j++){
                q = INT_MAX;
                if(!pos[j].size()) continue;
                for(int k = 0; k < pos[j].size(); k++){
                    if(pos[j][k] > p){
                        q = pos[j][k];
                        break;
                    }
                }
                if(q == INT_MAX) continue;
                else{
                    r = pos[i][pos[i].size() - 1];
                    if(r > q){
                        count++;
                    }
                }
                
            }
        }
        return count;
    }
};