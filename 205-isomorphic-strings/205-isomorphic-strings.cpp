class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> st, tt;
        for(int i = 0; i < s.size(); i++){
            if(st.count(t[i]) || tt.count(s[i])){
                if(st[t[i]] != s[i]){
                    return false;
                }
            }
            else{
                st[t[i]] = s[i];
                tt[s[i]] = t[i];
            }
        }
        return true;
    }
};