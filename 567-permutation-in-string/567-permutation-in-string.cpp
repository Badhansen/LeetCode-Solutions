class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        
        if(s1.length() > s2.length())
            return false;
        
        for(int i = 0; i < s1.length(); i++){
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }
        if(a == b)
            return true;
        for(int i = s1.length(); i < s2.length(); i++){
            b[s2[i]-'a']++;
            b[s2[i - s1.length()] - 'a']--;
            
            if(a == b)
                return true;
        }
        return false;
    }
};