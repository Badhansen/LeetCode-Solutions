// @Author: KING-SEN

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string ans;
        for(int i = 0; i < words.size(); i++){
            ans.append(words[i]);
            if(i != words.size() - 1){
                ans.push_back(' ');
            }
        }
        return ans;
    }
};