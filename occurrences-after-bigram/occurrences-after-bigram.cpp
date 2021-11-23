class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss;
        string prev, prev2, word;
        vector<string> answer;
        
        ss << text;
        
        while(ss >> word){
            if(prev2 == first && prev == second){
                answer.push_back(word);
            }
            prev2 = prev;
            prev = word;
        }
        
        return answer;
    }
};