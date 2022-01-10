class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        
        stringstream ss;
        ss << text;
        string word;
        
        while(ss >> word){
            words.push_back(word);
        }
        
        int spaceCount = 0;
        
        for(auto &c : text){
            if(c == ' ') spaceCount++;
        }
        
        int wordCount = words.size();
        int space = wordCount > 1 ? spaceCount / (wordCount - 1) : spaceCount;
        
        string answer;
        
        for(auto &w : words){
            if(answer.empty()){
                answer.append(w);
            }
            else{
                answer.append(string(space, ' '));
                answer.append(w);
            }
        }
        if(wordCount == 1){
            answer.append(string(space, ' '));
        }
        else if(wordCount > 1 && spaceCount % (wordCount - 1)){
            answer.append(string(spaceCount % (wordCount - 1), ' '));
        }
        
        return answer;
    }
};