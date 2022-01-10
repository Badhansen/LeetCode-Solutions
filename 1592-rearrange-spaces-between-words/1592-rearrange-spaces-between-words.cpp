class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        string word, ans;
        vector<string> words;
        for(auto &ch : text){
            if(ch == ' '){
                spaces++;
                if(!word.empty()){
                    words.push_back(word);
                }
                word = "";
            }
            else{
                word.push_back(ch);
            }
        }
        if(!word.empty()){
            words.push_back(word);
        }
        if(words.size() == 1){
            return words.back() + string(spaces, ' ');
        }
        int gap = spaces / (words.size() - 1), rem = spaces % (words.size() - 1);
        for(auto &w : words){
            ans.append(w + string(gap, ' '));
        }
        return ans.substr(0, ans.size() - gap) + string(rem, ' ');
    } 
};