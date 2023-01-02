class Solution {
public:
    bool isUpper(string& word){
        for(auto &c : word){
            if(!isupper(c)) return false;
        }
        return true;
    }
    bool isLower(string& word){
        for(auto &c : word){
            if(!islower(c)) return false;
        }
        return true;
    }
    bool isCapital(string& word){
        string wordNew = word.substr(1);
        if(isupper(word[0]) && isLower(wordNew))
            return true;
        return false;
    }
    bool detectCapitalUse(string word) {
        return isUpper(word) || isLower(word) || isCapital(word);
    }
};