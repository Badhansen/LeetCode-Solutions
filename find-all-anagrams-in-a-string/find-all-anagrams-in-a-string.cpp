class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        int count[27] = {0};
        for(const char &c : p){
            count[c - 'a']++;
        }
        
        int pUnique = 0;
        
        for(int i = 0; i < 27; i++){
            if(count[i]) pUnique++;
        }
        
        int start = 0;
        
        for(int end = 0; end < s.size(); end++){
            count[s[end] - 'a']--;
            if(count[s[end] - 'a'] == 0) pUnique--;
            else if(count[s[end] - 'a'] == -1) pUnique++;
            if(end - start + 1 > p.size()){
                count[s[start] - 'a']++;
                if(count[s[start] - 'a'] == 0) pUnique--;
                else if(count[s[start] - 'a'] == 1) pUnique++;
                start++;
            }
            if(pUnique == 0) answer.push_back(start);
        }
        
        return answer;
    }
};
