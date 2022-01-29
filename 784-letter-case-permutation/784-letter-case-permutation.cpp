class Solution {
public:
    vector<string> v;
    void go(int pos, string s){
        if(pos == s.size()){
            v.push_back(s);
            return;
        }
        else{
            go(pos + 1, s);
            if(s[pos] >= 'a' && s[pos] <= 'z'){
                s[pos] -= 32;
                go(pos + 1, s);
            }
            else if(s[pos] >= 'A' && s[pos] <= 'Z'){
                s[pos] += 32;
                go(pos + 1, s);
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        go(0, S);
        return v;
    }
};