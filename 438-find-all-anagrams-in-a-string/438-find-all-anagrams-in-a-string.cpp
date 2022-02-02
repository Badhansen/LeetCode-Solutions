class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer, sCount(26, 0), pCount(26, 0);
        
        for(const char &c : p){
            pCount[c - 'a']++;
        }
        
        int start = 0;
        
        for(int end = 0; end < s.size(); end++){
            sCount[s[end] - 'a']++;
            
            if(end - start + 1 == p.size()){
                if(sCount == pCount) 
                    answer.push_back(start);
            }
            else if(end - start + 1 > p.size()){
                sCount[s[start] - 'a']--;
                start++;
                
                if(sCount == pCount) 
                    answer.push_back(start);
            }
        }
        
        return answer;
    }
};
