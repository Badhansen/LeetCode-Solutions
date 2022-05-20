typedef unsigned long long ULL;
const int mod = 1e9 + 7;

class Solution {
private:
    ULL base = 1e9 + 7;
public:
    bool rabinKarp(string& text, int len, string& res){
        if(len == 0){
            return true;
        }
        if(len == text.size()){
            return false;
        }
        
        int tlen = text.size();
        ULL hash = 0, pmod = 1;
        set<ULL> seen;
        
        for(int i = 0; i < len - 1; i++){
            pmod = (pmod * base);
        }
        for(int i = 0; i < len; i++){
            hash = (hash * base + text[i]);
        }
        
        seen.insert(hash);
        
        for(int i = 1; i <= tlen - len; i++){
            hash = ((base * (hash - text[i - 1] * pmod)) + text[i + len - 1]);
           
            if(seen.count(hash)){
                res = text.substr(i, len);
                return true;
            }
            
            seen.insert(hash);
        }
        
        return false;
    }
    string longestDupSubstring(string s) {
        int low = 0, high = s.size();
        string ans = "";
        
        while(low <= high){
            int mid = (low + high) / 2;

            if(rabinKarp(s, mid, ans)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};