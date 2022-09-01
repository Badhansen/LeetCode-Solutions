class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sseen(256, -1), tseen(256, -1);
        for(int i = 0; i < s.size(); i++){
            if(sseen[t[i]] != -1 || tseen[s[i]] != -1){
                if(sseen[t[i]] != s[i]) return false;
            }
            else{
                sseen[t[i]] = s[i];
                tseen[s[i]] = t[i];
            }
        }
        return true;
    }
};
