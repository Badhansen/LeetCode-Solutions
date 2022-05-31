class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int need = 1 << k;
        for(int i = 0; i + k <= s.size(); i++){
            string a = s.substr(i, k);
            if(!st.count(a)){
                st.insert(a);
                need--;
                if(!need) return true;
            }
        }
        return false;
    }
};